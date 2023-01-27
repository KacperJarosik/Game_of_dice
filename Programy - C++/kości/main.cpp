#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

void welcome_information ();
void throws (int f_cubes []);
void map_cubes(int cubes_map[], int f_cubes[]);
int repeatable_value(int cubes_map[], int required_occurences);
void choice_option(int options[], int f_cubes[], bool repeat[]);
void game_board(int result[], bool f_used[]);
std::string circled(bool f_used[], int number);
int all_actual_points(int result[], bool f_used[]);
int school_actual_points(int result[], bool f_used[]);
int pair_options_repeatable_value(int cubes_map[]);
int two_pair_options_repeatable_value(int cubes_map[]);
int threesome_options_repeatable_value(int cubes_map[]);
int square_options_repeatable_value(int cubes_map[]);

int main()
{
    bool used_options[15] = {false};
    int scores[15] = {0};
    int cubes[5];
    welcome_information ();
    //petla gry
    for (int turn = 0; turn < 15; turn++)
    {
        //3 kolejne rzuty kostkami
        throws (cubes);
        game_board(scores, used_options);
        choice_option(scores, cubes, used_options);

    }
    std::cout << "Gratulacje !!!" <<std::endl << "Twoj wynik to: " << all_actual_points(scores, used_options);
}


void welcome_information ()
{
    std::cout <<"Witam w grze w kosci i zycze milej rozgrywki ^.^" << std::endl
              << "||------|| Zasady gry ||------||" << std::endl
              << "Celem gry jest zdobycie jak najwiekszej ilosci punktow po porzez przypisanie w odpowiedni sposob wylosowanych oczek na kostkach do odpowiednich pol z tabeli: " << std::endl
              << "Za skonczenie szkoly z wynikiem ujemnym otrzymuje sie dodatkowe - 50 pkt." << std::endl
              << "1) Jedynki - aby zaliczyc trzeba zdobyc odpowiednio trzy kostki z wynikiem 1. Kazda nadwyzka / niedobor skutkuje odpowiednio dodatkowymi / ujemnymi punktami. " << std::endl
              << "2) Dwojki - aby zaliczyc trzeba zdobyc odpowiednio trzy kostki z wynikiem 2. Kazda nadwyzka / niedobor skutkuje odpowiednio dodatkowymi / ujemnymi punktami. " << std::endl
              << "3) Trojki - aby zaliczyc trzeba zdobyc odpowiednio trzy kostki z wynikiem 3. Kazda nadwyzka / niedobor skutkuje odpowiednio dodatkowymi / ujemnymi punktami. " << std::endl
              << "4) Czworki - aby zaliczyc trzeba zdobyc odpowiednio trzy kostki z wynikiem 4. Kazda nadwyzka / niedobor skutkuje odpowiednio dodatkowymi / ujemnymi punktami. " << std::endl
              << "5) Piatki - aby zaliczyc trzeba zdobyc odpowiednio trzy kostki z wynikiem 5. Kazda nadwyzka / niedobor skutkuje odpowiednio dodatkowymi / ujemnymi punktami. " << std::endl
              << "6) Szostki - aby zaliczyc trzeba zdobyc odpowiednio trzy kostki z wynikiem 6. Kazda nadwyzka / niedobor skutkuje odpowiednio dodatkowymi / ujemnymi punktami. " << std::endl << std::endl
              << "7) Para - otrzymuje sie punkty za dwie takie same kostki z najwyzsza liczba oczek. W przypadku niespenienia warunku otrzymuje sie 0 pkt." << std::endl
              << "8) Dwie Pary - otrzymuje sie punkty za dwie takie same  lub różne pary kostek. W przypadku niespenienia warunku otrzymuje sie 0 pkt. " << std::endl
              << "9) Trojka - otrzymuje sie punkty za trzy takie same kostki. W przypadku niespenienia warunku otrzymuje sie 0 pkt. " << std::endl
              << "10) Kareta - otrzymuje sie punkty za cztery takie same kostki. W przypadku niespenienia warunku otrzymuje sie 0 pkt. " << std::endl
              << "11) General - otrzymuje sie punkty za piec takich samych kostek. W przypadku niespenienia warunku otrzymuje sie 0 pkt. " << std::endl
              << "12) Ful - otrzymuje sie punkty za trzy takie same kostki i jednoczesnie pare takich samych kostek. W przypadku niespenienia warunku otrzymuje sie 0 pkt. " << std::endl
              << "13) Maly Strit - otrzymuje sie punkty za kostki po kolei z mumerami 1, 2, 3, 4, 5 . W przypadku niespenienia warunku otrzymuje sie 0 pkt. " << std::endl
              << "14) Duzy strit - otrzymuje sie punkty za kostki po kolei z mumerami 2, 3, 4, 5, 6 . W przypadku niespenienia warunku otrzymuje sie 0 pkt. " << std::endl
              << "15) Szansa - otrzymuje sie punkty za sume wszystkich kostek. " << std::endl
              << "UWAGA: KAZDA OPCJĘ MOZNA WYBRAC TYLKO RAZ W CIAGU GRY" << std::endl;
}

void throws (int f_cubes [])
{
    srand(time(NULL));
    for (int throw_number = 1;throw_number<=3;throw_number++)
    {
        if (throw_number == 1)
        {
            f_cubes[0] = ((std::rand() % 6) + 1);
            f_cubes[1] = ((std::rand() % 6) + 1);
            f_cubes[2] = ((std::rand() % 6) + 1);
            f_cubes[3] = ((std::rand() % 6) + 1);
            f_cubes[4] = ((std::rand() % 6) + 1);
            std::cout << std::endl <<std::endl << std::endl << std::endl << std::endl << "Twoj pierwszy rzut to: [" << f_cubes[0] << "] [" << f_cubes[1] << "] [" << f_cubes[2] << "] [" << f_cubes[3] << "] [" << f_cubes[4] << "]" << std::endl << std::endl;
        }
        else
        {
            bool choice [5] = {false};
            std::cout << "Napisz po kolei, ktorymi kostkami chcesz rzucic ponownie.\n"
                      << "0 - zostawiam\n"
                      << "1 - rzucam ponownie\n"
                      << "np. 1 1 0 1 0, czyli rzucam ponownie: 1., 2., 4., natomiast kostki: 3., 5. zostają z takim samym wynikiem.\n";
            std::cin >> choice [0];
            std::cin >> choice [1];
            std::cin >> choice [2];
            std::cin >> choice [3];
            std::cin >> choice [4];
            if (choice [0])
            {
                f_cubes[0] = ((std::rand() % 6) + 1);
            }
            if (choice [1])
            {
                f_cubes[1] = ((std::rand() % 6) + 1);
            }
            if (choice [2])
            {
                f_cubes[2] = ((std::rand() % 6) + 1);
            }
            if (choice [3])
            {
                f_cubes[3] = ((std::rand() % 6) + 1);
            }
            if (choice [4])
            {
                f_cubes[4] = ((std::rand() % 6) + 1);
            }
            if (throw_number == 2)
            {
                std::cout << "Twoj drugi rzut to: [" << f_cubes[0] << "] [" << f_cubes[1] << "] [" << f_cubes[2] << "] [" << f_cubes[3] << "] [" << f_cubes[4] << "]" << std::endl << std::endl;
            }
            if (throw_number == 3)
            {
                std::cout << "Twoj trzeci rzut to: [" << f_cubes[0] << "] [" << f_cubes[1] << "] [" << f_cubes[2] << "] [" << f_cubes[3] << "] [" << f_cubes[4] << "]" << std::endl << std::endl;
            }
        }
    }
    return;
}


void choice_option(int options[], int f_cubes[], bool repeat[]) {
    std::cout << "Wybierz opcję z tabeli\n";
    bool correct_run = false;
    while (!correct_run) {
        correct_run = true;
        int result;
        int cubes_map[6];
        map_cubes(cubes_map, f_cubes);
        int chosen_option = 1000;
        std::cin >> chosen_option;
        if (repeat[chosen_option - 1]) {
            std::cout << "Ta opcja jest już wykorzystana wybierz poprawną opcje" << std::endl;
            correct_run = false;
            continue;
        }
        switch (chosen_option - 1) {
//wpis do "jedynki"
            case 0:
                result = cubes_map[0] * 1 - 3;
                options[0] = result;
                std::cout << "Twoj wynik w \"jedynki\" to: " << result << std::endl;
                repeat[0] = true;
                break;
//wpis do "dwójki"
            case 1:
                result = cubes_map[1] * 2 - 6;
                options[1] = result;
                std::cout << "Twoj wynik w \"dwojki\" to: " << result << std::endl;
                repeat[1] = true;
                break;
//wpis do "trójki"
            case 2:
                result = cubes_map[2] * 3 - 9;
                options[2] = result;
                std::cout << "Twoj wynik w \"trojki\" to: " << result << std::endl;
                repeat[2] = true;
                break;
//wpis do "czwórki"
            case 3:
                result = cubes_map[3] * 4 - 12;
                options[3] = result;
                std::cout << "Twoj wynik w \"czworki\" to: " << result << std::endl;
                repeat[3] = true;
                break;
//wpis do "piątki"
            case 4:
                result = cubes_map[4] * 5 - 15;
                options[4] = result;
                std::cout << "Twoj wynik w \"piatki\" to: " << result << std::endl;
                repeat[4] = true;
                break;
//wpis do "szóstki"
            case 5:
                result = cubes_map[5] * 6 - 18;
                options[5] = result;
                std::cout << "Twoj wynik w \"szostki\" to: " << result << std::endl;
                repeat[5] = true;
                break;
//wpis do "para"
            case 6:
                result = pair_options_repeatable_value (cubes_map);
                options[6] = result;
                std::cout << "Twoj wynik w \"para\" to: " << result << std::endl;
                repeat[6] = true;
                break;
//dwie pary
            case 7:
                result = two_pair_options_repeatable_value (cubes_map);
                options[7] = result;
                std::cout << "Twoj wynik w \"dwie pary\" to: " << result << std::endl;
                repeat[7] = true;
                break;
//wpis do "trójka"
            case 8:
                result = threesome_options_repeatable_value(cubes_map);
                options[8] = result;
                std::cout << "Twoj wynik w \"trojka\" to: " << result << std::endl;
                repeat[8] = true;
                break;
//wpis do "kareta"
            case 9:
                result = square_options_repeatable_value(cubes_map);
                options[9] = result;
                std::cout << "Twoj wynik w \"kareta\" to: " << result << std::endl;
                repeat[9] = true;
                break;
//wpis do "generał"
            case 10:
                result = repeatable_value(cubes_map, 5);
                options[10] = result;
                std::cout << "Twoj wynik w \"general\" to: " << result << std::endl;
                repeat[10] = true;
                break;
//wpis do "ful"
            case 11:
                result = repeatable_value(cubes_map, 3) + repeatable_value(cubes_map, 2);
                if (result == 0)
                {
                    result = repeatable_value(cubes_map, 5);
                }
                options[11] = result;
                std::cout << "Twoj wynik w \"ful\" to: " << result << std::endl;
                repeat[11] = true;
                break;
//wpis do "mały strit"
            case 12:
                if (cubes_map[0] == 1 && cubes_map[1] == 1 && cubes_map[2] == 1 && cubes_map[3] == 1 && cubes_map[4] == 1)
                {
                    result = 15;
                }
                else
                {
                    result = 0;
                }
                options[12] = result;
                std::cout << "Twoj wynik w \"maly strit\" to: " << result << std::endl;
                repeat[12] = true;
                break;
//wpis do "duży strit"
            case 13:
                if (cubes_map[1] == 1 && cubes_map[2] == 1 && cubes_map[3] == 1 && cubes_map[4] == 1 &&
                    cubes_map[5] == 1)
                {
                    result = 20;
                }
                else
                {
                    result = 0;
                }
                options[13] = result;
                std::cout << "Twoj wynik w \"duzy strit\" to: " << result << std::endl;
                repeat[13] = true;
                break;
//wpis do "szansa"
            case 14:

                result = f_cubes[0] + f_cubes[1] + f_cubes[2] + f_cubes[3] + f_cubes[4];
                options[14] = result;
                std::cout << "Twoj wynik w \"szansa\" to: " << result << std::endl;
                repeat[14] = true;

                break;

// źle wybrana opcja
            default:
                std::cout << "Wybierz poprawną opcje" << std::endl;

        }
    }
    return;
}


void map_cubes(int cubes_map[], int f_cubes[])
{
    for (int i = 0; i < 5; i++)
    {
        cubes_map[i] = 0;
    }

    for (int i = 0; i < 5; i++)
    {
        cubes_map[f_cubes[i] - 1] += 1;
    }

    return;
}


int repeatable_value(int cubes_map[], int required_occurences)
{
    for (int i = 5; i >= 0; i--) {
        if (cubes_map[i] == required_occurences)
        {
            return required_occurences * (i + 1);
        }
    }
    return 0;
}


void game_board(int result[], bool f_used[])
{
    std::cout << "AKTUALNA PUNKTACJA\n"
              << "SZKOŁA\n"
              << "1) Jedynki: " << result[0] << circled(f_used, 0) << std::endl
              << "2) Dwojki: " << result[1] << circled(f_used, 1) << std::endl
              << "3) Trojki: " << result[2] << circled(f_used, 2) << std::endl
              << "4) Czworki: " << result[3] << circled(f_used, 3) << std::endl
              << "5) Piatki: " << result[4] << circled(f_used, 4) << std::endl
              << "6) Szostki: " << result[5] << circled(f_used, 5) << std::endl
              << "Suma szkola: " << school_actual_points (result, f_used) << std::endl
              << "OGÓLNE\n"
              << "7) Para: " << result[6] << circled(f_used, 6) << std::endl
              << "8) Dwie Pary: " << result[7] << circled(f_used, 7) << std::endl
              << "9) Trojka: " << result[8] << circled(f_used, 8) << std::endl
              << "10) Kareta: " << result[9] << circled(f_used, 9) << std::endl
              << "11) General: " << result[10] << circled(f_used, 10) << std::endl
              << "12) Ful: " << result[11] << circled(f_used, 11) << std::endl
              << "13) Maly Strit: " << result[12] << circled(f_used, 12) << std::endl
              << "14) Duzy strit: " << result[13] << circled(f_used, 13) << std::endl
              << "15) Szansa: " << result[14] << circled(f_used, 14) << std::endl
              << "Aktualny wynik: " << all_actual_points(result, f_used) << std::endl;
    return;
}


std::string circled(bool f_used[], int number)
{
    std::string x = " ";
    if (f_used[number])
    {
        x += "[x]";
    }
    return x;
}


int all_actual_points(int result[], bool f_used[])
{
    int final_score = 0;
    for (int i = 0; i < 15; i++)
    {
        final_score += result[i];
    }
    if (f_used[0] && f_used[1] && f_used[2] && f_used[3] && f_used[4] && f_used[5])
    {
        final_score -= 50;
    }
    return final_score;
}


int school_actual_points (int result[], bool f_used[])
{
    int school_score = result[0] + result[1] + result[2] + result[3] + result[4] + result[5];
    if (f_used[0] && f_used[1] && f_used[2] && f_used[3] && f_used[4] && f_used[5])
    {
        school_score -= 50;
    }
    return school_score;
}


int pair_options_repeatable_value(int cubes_map[])
{
    int down_pair = 0;
    int up_pair = 0;

    for (int i = 5; i >= 0; i--)
    {
        if (cubes_map[i] == 2)
        {
            up_pair = 2 * (i + 1);
        }
    }
    for (int i = 0; i <= 5; i++)
    {
        if (cubes_map[i] == 2)
        {
            down_pair = 2 * (i + 1);
        }
    }
    if ( up_pair > down_pair)
    {
        return up_pair;
    }
    if ( up_pair < down_pair)
    {
        return down_pair;
    }
    for (int i = 5; i >= 0; i--)
    {
        if (cubes_map[i] == 3)
        {
            return 2 * (i + 1);
        }
    }
    for (int i = 5; i >= 0; i--)
    {
        if (cubes_map[i] == 4)
        {
            return 2 * (i + 1);
        }
    }
    for (int i = 5; i >= 0; i--)
    {
        if (cubes_map[i] == 5)
        {
            return 2 * (i + 1);
        }
    }
    return 0;
}


int two_pair_options_repeatable_value(int cubes_map[])
{
    int down_pair = 0;
    int up_pair = 0;

    for (int i = 5; i >= 0; i--)
    {
        if (cubes_map[i] == 2)
        {
            up_pair = 2 * (i + 1);
        }
        else
        {
            return 0;
        }
    }
    for (int i = 0; i <= 5; i++)
    {
        if (cubes_map[i] == 2)
        {
            down_pair = 2 * (i + 1);
        }
        else
        {
            return 0;
        }
    }
    if ( up_pair != down_pair)
    {
        return up_pair + down_pair;
    }
    else
    {
        return 0;
    }
}


int threesome_options_repeatable_value(int cubes_map[])
{
    for (int i = 5; i >= 0; i--)
    {
        if (cubes_map[i] == 3)
        {
            return  3 * (i + 1);
        }
    }
    for (int i = 5; i >= 0; i--)
    {
        if (cubes_map[i] == 4)
        {
            return  3 * (i + 1);
        }
    }
    for (int i = 5; i >= 0; i--)
    {
        if (cubes_map[i] == 5)
        {
            return  3 * (i + 1);
        }
    }
    return 0;
}


int square_options_repeatable_value(int cubes_map[])
{
    for (int i = 5; i >= 0; i--)
    {
        if (cubes_map[i] == 4)
        {
            return  4 * (i + 1);
        }
    }
    for (int i = 5; i >= 0; i--)
    {
        if (cubes_map[i] == 5)
        {
            return  4 * (i + 1);
        }
    }
    return 0;
}