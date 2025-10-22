#include <iostream>
#include "DeckGrader.h"

// Deckgrader Constructor
// Scoring system for each role
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

// Calculate average elixir cost of deck
double DeckGrader::getAvgElixir(const Deck& deck){
    const auto&cards = deck.getCards(); // get all cards
    if (cards.empty()){
        return 0.0;
    }
    double totalElixir = 0;
    for (const auto& c : cards){
        totalElixir = totalElixir + c.getCardElixir(); // sum up elixir costs
    }
    double avgElixir = 0;
    avgElixir = totalElixir/8; 
    return avgElixir;
}

// Computes overall grade 
double DeckGrader::gradeDeck(const Deck& deck){

    double balanceScore = gradeBalance(deck);
    double attackScore = gradeAttack(deck);
    double defenseScore = gradeDefense(deck);

    double overallScore = 0;
    overallScore = (attackScore + defenseScore)*balanceScore/100; // weighted combination
    return overallScore;
}

// Computes attacking grade
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

// Computes defensive grade
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

// Computes strength grade
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

// Computes balance of deck
double DeckGrader::gradeBalance(const Deck& deck) {
    std::unordered_map<std::string, int> roleCount;
    
    // Count how many cards exist for each role
    for (const auto& card : deck.getCards()) {
        roleCount[card.getCardRole()]++;
    }

    double balanceScore = 0;

    // Iterate over each role and calculate score based on the number of cards
    for (auto it = roleScores.begin(); it != roleScores.end(); ++it) {
        const std::string& role = it->first;
        auto& roleMap = it->second;

        int count = 0;
        if (roleCount.count(role))
            count = roleCount[role];

        int score = 0;
        if (roleMap.count(count))
            score = roleMap[count]; // Use defined score
        else {
            // If count exceeds defined map, use score of max count
            int maxCount = 0, lastScore = 0;
            for (auto rit = roleMap.begin(); rit != roleMap.end(); ++rit) {
                if (rit->first > maxCount) {
                    maxCount = rit->first;
                    lastScore = rit->second;
                }
            }
            score = lastScore;
        }

        balanceScore += score; // add score for this role
    }

    // normalise as percentage
    double balance = balanceScore / 90.0 * 100.0;
    return balance;
}