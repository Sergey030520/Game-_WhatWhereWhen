#include <iostream>
#include <fstream>

std::ifstream question, answer;
bool sectors[13];

void loading_data(){
    for (int numb_sector = 0; numb_sector < 13; ++numb_sector) sectors[numb_sector] = false;
    question.open("C:\\Users\\Malip\\source\\repos\\Game_WhatWhereWhen\\question.txt", std::ios::binary);
    answer.open("C:\\Users\\Malip\\source\\repos\\Game_WhatWhereWhen\\answer.txt", std::ios::binary);
}
int spin_reels(int current_pos, int offset){
    current_pos += offset;
    if (current_pos > 12) current_pos -= 12;
    if (sectors[current_pos]) current_pos = spin_reels(current_pos, 1);
    return current_pos;
}
bool checking_answer(int numb_sector, std::string user_answer){
    answer.seekg(0);
    std::string copy_answer;
    for(int numb_answer = 0; numb_answer <= numb_sector; ++numb_answer) answer >> copy_answer;
    return user_answer == copy_answer;
}
void show_answer(int numb_question){
    std::string copy_quest;
    question.seekg(0);
    for (int numb = 0; numb < numb_question+1; ++numb) getline(question, copy_quest);
    std::cout << copy_quest << std::endl;
}

int main() {
    int tv_viewers = 0, connoisseur = 0;
    int offset, current_pos = 0;
    loading_data();
    while(tv_viewers != 6 && connoisseur != 6){
        std::string user_answer;
        std::cout << "Input the offset: ";
        std::cin >> offset;
        current_pos = spin_reels(current_pos, offset);
        show_answer(current_pos);
        std::cout << "Input answer: ";
        std::cin >> user_answer;
        if (checking_answer(current_pos, user_answer)) {
            connoisseur++;
            std::cout << "You guessed it!\n" << "Score points: players " << connoisseur << ", tv viewers "
                << tv_viewers << std::endl;
        }
        else {
            tv_viewers++;
            std::cout << "You didn't guess!\n" << "Score points: players " << connoisseur << ", tv viewers "
                      << tv_viewers << std::endl;
        }
        sectors[current_pos] = true;
    }
    if (connoisseur == 6) std::cout << "Connoisseur is win!" << std::endl;
    else  std::cout << "TV viewers is win!" << std::endl;
}