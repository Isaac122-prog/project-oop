#include <iostream>
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

    double overallScore = 0;
    overallScore = (attackScore + defenseScore)*balanceScore/100;
    return overallScore;
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
        totalDefense = totalDefense + c.getCardDefence();
    }
    double defense = totalDefense / elixir; 
    return defense;
}

double DeckGrader::gradeStrength(const Deck& deck) {
    double elixir = getAvgElixir(deck);
    const auto& cards = deck.getCards();
    if (cards.empty()){
        return 0.0;
    }
    double totalStrength = 0;
    for (const auto& c : cards){
        totalStrength = totalStrength + c.getCardHealth();
    }
    double strength = totalStrength / elixir; 
    return strength;
}

double DeckGrader::gradeBalance(const Deck& deck) {
    std::unordered_map<std::string, int> roleCount;
    
    for (const auto& card : deck.getCards()) {
        roleCount[card.getCardRole()]++;
    }

    double balanceScore = 0;

    for (auto it = roleScores.begin(); it != roleScores.end(); ++it) {
        const std::string& role = it->first;
        auto& roleMap = it->second;

        int count = 0;
        if (roleCount.count(role))
            count = roleCount[role];

        int score = 0;
        if (roleMap.count(count))
            score = roleMap[count];
        else {
            int maxCount = 0, lastScore = 0;
            for (auto rit = roleMap.begin(); rit != roleMap.end(); ++rit) {
                if (rit->first > maxCount) {
                    maxCount = rit->first;
                    lastScore = rit->second;
                }
            }
            score = lastScore;
        }

        balanceScore += score;
    }

    double balance = balanceScore / 90.0 * 100.0;
    return balance;
}