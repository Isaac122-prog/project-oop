#include "DeckGrader.h"

DeckGrader::DeckGrader(){
    roleScores = {
        {"WinCon",       {{0,5},{1,10},{2,7},{3,5},{4,3},{5,0},{6,-3},{7,-5},{8,-10}}},
        {"AntiAir",      {{0,7},{1,10},{2,7},{3,5},{4,3},{5,0},{6,-1},{7,-3},{8,-5}}},
        {"CheapAntiAir", {{0,8},{1,10},{2,8},{3,6},{4,3},{5,0},{6,-1},{7,-3},{8,-5}}},
        {"HeavyTank",    {{0,8},{1,10},{2,8},{3,5},{4,0},{5,-2},{6,-4},{7,-6},{8,-10}}},
        {"MiniTank",     {{0,7},{1,10},{2,8},{3,6},{4,3},{5,0},{6,-1},{7,-3},{8,-5}}},
        {"SmallSpell",   {{0,6},{1,10},{2,8},{3,6},{4,3},{5,0},{6,-1},{7,-3},{8,-5}}},
        {"BigSpell",     {{0,7},{1,10},{2,6},{3,4},{4,0},{5,-1},{6,-3},{7,-5},{8,-10}}},
        {"Distraction",  {{0,7},{1,10},{2,9},{3,6},{4,3},{5,0},{6,-1},{7,-3},{8,-10}}},
        {"Building",     {{0,8},{1,10},{2,7},{3,5},{4,0},{5,-1},{6,-3},{7,-5},{8,-10}}},
    };
}

double DeckGrader::getAvgElixir(const Deck& deck){
    const auto&cards = deck.getCards();
    if (cards.empty()){
        return 0.0;
    }
    double totalElixir = 0;
    for (const auto& c : cards){
        totalElixir = totalElixir + c.getCardElixir();
    }
    double avgElixir = 0;
    avgElixir = totalElixir/8; 
    return avgElixir;
}

double DeckGrader::gradeDeck(const Deck& deck){

    double balanceScore = gradeBalance(deck);
    double attackScore = gradeAttack(deck);
    double defenseScore = gradeDefense(deck);

}

double DeckGrader::gradeAttack(const Deck& deck){
    double elixir = getAvgElixir(deck);
    const auto& cards = deck.getCards();
    if (cards.empty()){
        return 0.0;
    }
    double totalAttack = 0;
    for (const auto& c : cards){
        totalAttack = totalAttack + c.getCardAttack();
    }
    double attack = totalAttack / elixir; 
    return attack;
}

double DeckGrader::gradeDefense(const Deck& deck){
    double elixir = getAvgElixir(deck);
    const auto& cards = deck.getCards();
    if (cards.empty()){
        return 0.0;
    }
    double totalDefense = 0;
    for (const auto& c : cards){
        totalDefense = totalDefense + c.getCardAttack();
    }
    double defense = totalDefense / elixir; 
    return defense;
}

double DeckGrader::gradeBalance(const Deck& deck){
}