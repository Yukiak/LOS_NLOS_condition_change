#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <math.h>

std::vector < std::vector < std::string >> signal_status(100000, std::vector <std::string>(100)); //signal_status‚Ìƒf[ƒ^‚ğŠi”[‚·‚é•Ï”
int countcolumns[1000000] = { 0 }; //countcolumns[i]=j‚Ì‚Æ‚«Ais–Ú‚Ì—ñ”‚Íj

int main() {

    //signal_status“Ç‚İ‚İ
    std::ifstream ifs("signal_status.txt");
    std::string str="";

    if (!ifs) {
        std::cout << "Error! File can not be opened" << std::endl;
        return -1;
    }

    int i = 0;
    int j = 0;

    while (getline(ifs, str)) {
        std::string tmp="";
        std::istringstream stream(str);

        while (getline(stream, tmp, ',')) {
            signal_status[i][j] = tmp;
            j++;
        }

        countcolumns[i] = j - 1;

        j = 0;
        i++;
    }

    std::ofstream output("signal_status NSAT.txt");

    int k = 0;
    int l = 0;

    for (k = 0; k < 23767; k++) {

        for (l = 0;l < countcolumns[k]; l++) {

            if (l == 0) {
                output << signal_status[k][0] << ",";
                //std::cout << stod(signal_status[k][0] )<< std::endl;
            }

            if (l != 0) {
                if (countcolumns[k] / 2 <= 9) { //NSAT‚ªZˆÈ‰º‚È‚ç...
                   
                    if (l % 2 == 1) {
                        output << stoi(signal_status[k][l]) << ",";
                        //std:: cout << stoi(signal_status[k][l]) << std::endl;
                    } else {
                        output << 1 << ","; //‘S‚Ä‚Ì‰q¯‚ğLOS‚É
                    }
                   
                } else {
                    output << stoi(signal_status[k][l]) << ",";
                    //std::cout << stoi(signal_status[k][l]) << std::endl;
                }
            }

        }

        output << stoi(signal_status[k][countcolumns[k]]) <<std::endl;

    }

    return 0;

}

