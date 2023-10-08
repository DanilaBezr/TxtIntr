#include <iostream>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc==1)
    {
        cout<<"КАЛЬКУЛЯТОР"<< endl<< "Чтобы выбрать действие, нужно ввести один из параметров:" << endl<< "-m — умножение всех введенных значений" << endl << "-d — деление первого значения на все последующие введенные значения"<< endl << "Для того чтобы продолжить запустите программу еще раз с нужным параметром и введите значения через пробел"<< endl;
        return 0;
    }
    if (argc < 5 or argc > 7)
    {
        cout << "Программа принимает от 3 до 5 параметров для выполнения операции. Попробуйте снова." << endl;
        return 0;
    }

    int opt, i = 0;
    double result = 1.0;
    
    struct option long_options[] = {
    {"multiply", no_argument, NULL, 'm'},
    {"divison", no_argument, NULL, 'd'},
    {NULL, 0, NULL, 0}
    };
    
    int option_index = 0;
    while ((opt = getopt_long(argc, argv, "md", long_options, &option_index)) != -1)
    {
        switch (opt)
        {
            case 'm': // умножение
                for (i = optind; i < argc; ++i)
                {
                    result *= atof(argv[i]);
                }
                cout << "Результат умножения: " << result << endl;
                break;
            case 'd': //деление
                if(argc-optind<2) {
                    cout << "Для деления нужно как минимум два числа" << endl;
                    break;
                }

                result = atof(argv[optind]);
                for (i = optind + 1; i < argc; ++i)
                {
                    double divisor = atof(argv[i]);
                    if (divisor != 0.0)
                        result /= divisor;
                    else {
                        cout<< "Ошибка: деление на ноль невозможно" << endl;
                        return 1;
                    }
                }
                cout << "Результат деления : " << result << endl;
                break;
            default:
                cerr << "Неизвестный параметр" << '\n';
                break;
        }
    }
}
