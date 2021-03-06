﻿#include "gtest/gtest.h"
#include "CardGame.h"
#include "CardShark.h"
#include "Looser.h"

//! Тест конструктора без параметров
TEST(CardShark, DefaultConstructor) {
	CardShark CardShark;
	ASSERT_EQ(36, CardShark.getCardsNumber());
	ASSERT_EQ(0, CardShark.getCurrentScore());
}

//! Тест геттера, который возвращает номер хода, на котором используется суперспособность.
TEST(CardShark, SuperSkillTimeCame) {
	CardShark CardShark;
	ASSERT_EQ(1, CardShark.isSuperSkillTimeCame(CardShark.getSuperSkillMoveNumber()));
}

//! Тест геттера, который возвращает номер хода, на котором используется суперспособность, на стабильность.
TEST(CardShark, SuperSkillTimeCameStability) {
	CardShark CardShark;
	ASSERT_EQ(0, CardShark.isSuperSkillTimeCame(-123));
}

//! Тест метода, который инкрементирует счетчик количества баллов игрока.
TEST(CardShark, Increment) {
	CardShark CardShark;
	CardShark.increment();
	ASSERT_EQ(1, CardShark.getCurrentScore());
}

//! Тест на диапазон значений результата игры.
TEST(CardGame, GetResult) {
	CardShark cardShark;
	Looser looser;
	CardGame game(cardShark, looser);
	game.startGame();
	ASSERT_LT(-1, game.getResult());
	ASSERT_GT(3, game.getResult());
}

//! Тест унарного префиксного оператора.
TEST(CardShark, OperatorIncrement) {
	CardShark CardShark;
	++CardShark; 
	ASSERT_LT(0, CardShark.getCurrentScore());
	ASSERT_GT(3, CardShark.getCurrentScore());
}

//! Тест бинарного оператора сравнения.
TEST(CardShark, OperatorLessThan) {
	CardShark cardShark;
	Looser looser;
	++cardShark;
	ASSERT_EQ(1, cardShark < looser);
}

//! Тест оператора инкремент класса Looser.
TEST(Looser, OperatorIncrement) {
	Looser looser;
	++looser;
	ASSERT_LT(-1, looser.getCurrentScore());
	ASSERT_GT(2, looser.getCurrentScore());
}

//! Тест сеттера класса Player.
TEST(Player, setCardsNumber) {
	CardShark cardShark;
	cardShark.setCardsNumber(123);
	ASSERT_EQ(123, cardShark.getCardsNumber());
}

//! Тест геттера класса Exception.
TEST(Exception, getExceptionName) {
	Exception exception("ERROR");
	ASSERT_STREQ("ERROR", exception.getExceptionName().c_str());
}

//! Тест метода startChampionship класса CardGame.
TEST(CardGame, startChampionship) {
	int n = 3;
	std::vector<CardShark> player1(n);
	std::vector<Looser> player2(n);
	CardGame game(player1, player2);
	game.startChampionship();
	for (int i = 0; i < 2*n; i++)
	{
		ASSERT_LT(-1, game.getResultTable(i));
		ASSERT_GT(n+1, game.getResultTable(i));
	}
}

int main(int argc, char ** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	if (!RUN_ALL_TESTS())
	{
		std::cout << "All Tests are Passed." << std::endl;
	}
	else
	{
		std::cerr << "One or more tests FAILED!" << std::endl;
	}
	return 0;
}
