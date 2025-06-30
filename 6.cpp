#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    const double PI = 3.141592653589793;
    const double x_min = 0.0;
    const double x_max = 4.0 * PI;
    const double step = 0.1;

    std::ofstream file("senoide.bin", std::ios::binary);
    if (!file) {
        std::cerr << "Erro ao abrir o arquivo senoide.bin para escrita." << std::endl;
        return 1;
    }

    for (double x = x_min; x <= x_max; x += step) {
        double y = 2.0 * sin(1.0 * x);
        file.write(reinterpret_cast<char*>(&x), sizeof(double));
        file.write(reinterpret_cast<char*>(&y), sizeof(double));
    }

    file.close();

    std::ofstream script("script.gp");
    if (!script) {
        std::cerr << "Erro ao criar o arquivo script.gp." << std::endl;
        return 1;
    }

    script << "set title 'Gráfico da Senoide'\n";
    script << "set xlabel 'x'\n";
    script << "set ylabel 'y'\n";
    script << "set grid\n";
    script << "plot 'senoide.bin' binary format='%double%double' using 1:2 with lines title 'y = 2*sin(x)'\n";

    script.close();

    // Executa o script via GNUplot
    system("gnuplot -persist script.gp");

    return 0;
}
