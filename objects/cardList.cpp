#include "cardList.h"
#include "gameCard.h"
#include "heroCard.h"
	
#include <algorithm>
#include <chrono>
#include <stdexcept>

namespace Object
{

CardList::CardList(const std::string& setting)
{
	image = loadImage("Images/Cards/back.png", true);
	if(setting == "empty")
	{
		//do nothing
	}
	else if(setting == "standard_playing_cards")
		loadCardDeck();
	else if(setting == "hero_deck")
		loadHeroDeck();
	else
		throw std::runtime_error("no such deck type as: " + setting);
	
	//shuffle(); //blanda listan fint^^
}
	
CardList::~CardList()
{
		
	while(!set.empty())
	{
		delete set.back();
		set.pop_back(); //??? fungerar detta? eller fuckas det upp med pekare? testa det vet ja :) 
	}
}
	
Card* CardList::drawCard()
{
	Card* c = set.front();
	set.front() = nullptr; //peka bort så att vi inte tar bort c ^^
	set.erase(set.begin());
	return c;
}

bool CardList::empty()
{
	return set.empty();
}
void CardList::pushBottom(Card* card)
{
	set.push_back(card);
	card = nullptr;
}
	
void CardList::pushTop(Card* card)
{
	set.insert(set.begin(), card);
	card = nullptr; 
}
	
void CardList::shuffle()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::shuffle (set.begin(), set.end(), std::default_random_engine(seed));
}

//kolla inte här nere... du blir bara ledsen :'(

// <maxHP> <clan> <male> <abilities>

void CardList::loadHeroDeck()
{
	//lägger 3 emparors först för att underlätta grejer :)
	set.push_back(new HeroCard("CaoCao.png", "4 blue 1 ability"));
	set.push_back(new HeroCard("LiuBei.png", "4 red 1 ability"));
	set.push_back(new HeroCard("SunQuan.png", "4 green 1 ability"));
	//resten
	set.push_back(new HeroCard("DaQiao.png", "3 green 0 ability"));
	set.push_back(new HeroCard("DiaoChan.png", "3 gray 0 ability"));
	set.push_back(new HeroCard("ElderZhuge.png", "3 red 1 ability"));
	set.push_back(new HeroCard("GanNing.png", "4 green 1 ability"));
	set.push_back(new HeroCard("GuanYu.png", "4 red 1 ability"));
	set.push_back(new HeroCard("GuoJia.png", "3 blue 1 ability"));
	set.push_back(new HeroCard("HuangGai.png", "4 green 1 ability"));
	set.push_back(new HeroCard("HuangYueYing.png", "3 red 0 ability"));
	set.push_back(new HeroCard("HuaTuo.png", "3 gray 1 ability"));
	set.push_back(new HeroCard("LuBu.png", "4 gray 1 ability"));
	set.push_back(new HeroCard("LuMeng.png", "4 green 1 ability"));
	set.push_back(new HeroCard("LuXun.png", "3 green 1 ability"));
	set.push_back(new HeroCard("MaChao.png", "4 red 1 ability"));
	set.push_back(new HeroCard("SiMaYi.png", "3 blue 1 ability"));
	set.push_back(new HeroCard("SunShangXiang.png", "3 green 0 ability"));
	set.push_back(new HeroCard("XiaHouDun.png", "4 blue 1 ability"));
	set.push_back(new HeroCard("XuChu.png", "4 blue 1 ability"));
	set.push_back(new HeroCard("ZhangFei.png", "4 red 1 ability"));
	set.push_back(new HeroCard("ZhangLiao.png", "4 blue 1 ability"));
	set.push_back(new HeroCard("ZhaoYun.png", "4 red 1 ability"));
	set.push_back(new HeroCard("ZhenJi.png", "3 blue 0 ability"));
	set.push_back(new HeroCard("ZhouYu.png", "3 green 1 ability"));
}

void CardList::loadCardDeck()
{
	//attackses
// 1 = targettable, 10 = weapon range
set.push_back(new GameCard(7,spades,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(8,spades,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(9,spades,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(10,spades,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(8,spades,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(9,spades,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(10,spades,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(13,diamonds,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(6,diamonds,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(7,diamonds,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(8,diamonds,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(9,diamonds,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(10,diamonds,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(10,hearts,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(10,hearts,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(11,hearts,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(8,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(9,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(10,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(11,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(2,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(3,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(4,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(5,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(6,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(7,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(8,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(9,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(10,clubs,"attack.png","attack 1 10")); //ability id, target type, target range
set.push_back(new GameCard(11,clubs,"attack.png","attack 1 10")); //ability id, target type, target range

//dodges
//0 = self/instant, 0 = no range
set.push_back(new GameCard(2,diamonds,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(3,diamonds,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(4,diamonds,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(5,diamonds,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(6,diamonds,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(7,diamonds,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(8,diamonds,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(9,diamonds,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(10,diamonds,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(11,diamonds,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(11,diamonds,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(2,diamonds,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(2,hearts,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(13,hearts,"dodge.png","dodge 0 0")); //ability id, target type, target range
set.push_back(new GameCard(2,hearts,"dodge.png","dodge 0 0")); //ability id, target type, target range

//peaches
//0 = self-instant, 0 = no range
set.push_back(new GameCard(3,hearts,"peach.png","heal 0 0")); //ability id, target type, target range
set.push_back(new GameCard(9,hearts,"peach.png","heal 0 0")); //ability id, target type, target range
set.push_back(new GameCard(8,hearts,"peach.png","heal 0 0")); //ability id, target type, target range
set.push_back(new GameCard(7,hearts,"peach.png","heal 0 0")); //ability id, target type, target range
set.push_back(new GameCard(6,hearts,"peach.png","heal 0 0")); //ability id, target type, target range
set.push_back(new GameCard(12,hearts,"peach.png","heal 0 0")); //ability id, target type, target range
set.push_back(new GameCard(12,diamonds,"peach.png","heal 0 0")); //ability id, target type, target range
set.push_back(new GameCard(4,hearts,"peach.png","heal 0 0")); //ability id, target type, target range

//horses
// 5 = equipment, 0 = no range
set.push_back(new GameCard(13,spades,"da_wan.png","off_horse 5 0")); //ability id, target type, target range
set.push_back(new GameCard(5,hearts,"chi_tu.png","off_horse 5 0")); //ability id, target type, target range
set.push_back(new GameCard(13,diamonds,"zi_xin.png","off_horse 5 0")); //ability id, target type, target range
set.push_back(new GameCard(5,spades,"jue_ying.png","def_horse 5 0")); //ability id, target type, target range
set.push_back(new GameCard(5,clubs,"di_lu.png","def_horse 5 0")); //ability id, target type, target range
set.push_back(new GameCard(13,hearts,"zhua_huang.png","def_horse 5 0")); //ability id, target type, target range

//weaponzies and shieldzes
//
set.push_back(new GameCard(6,spades,"blue_steel_blade.png","blue_steel_blade_equip 5 0")); //ability id, target type, target range
set.push_back(new GameCard(2,spades,"double_gender_sword.png","double_gender_sword_equip 5 0")); //ability id, target type, target range
set.push_back(new GameCard(5,spades,"green_dragon_cresent_blade.png","green_dragon_cresent_blade_equip 5 0")); //ability id, target type, target range
set.push_back(new GameCard(12,spades,"serpent_halberd.png","serpent_halberd_equip 5 0")); //ability id, target type, target range
set.push_back(new GameCard(5,hearts,"unicorn_bow.png","unicorn_bow_equip 5 0")); //ability id, target type, target range
set.push_back(new GameCard(1,clubs,"zhuge_crossbow.png","zhuge_crossbow_equip 5 0")); //ability id, target type, target range
set.push_back(new GameCard(1,diamonds,"zhuge_crossbow.png","zhuge_crossbow_equip 5 0")); //ability id, target type, target range
set.push_back(new GameCard(5,diamonds,"rock_cleaving_axe.png","rock_cleaving_axe_equip 5 0")); //ability id, target type, target range
set.push_back(new GameCard(12,diamonds,"Heaven_Scorcher_Halberd.png","Heaven_Scorcher_Halberd_equip 5 0")); //ability id, target type, target range
set.push_back(new GameCard(2,spades,"ba_gua_shield.png","ba_gua_shield_equip 5 0")); //ability id, target type, target range
set.push_back(new GameCard(2,clubs,"ba_gua_shield.png","ba_gua_shield_equip 5 0")); //ability id, target type, target range
set.push_back(new GameCard(2,spades,"frost_blade.png","frost_blade 5 0")); //ability id, target type, target range
set.push_back(new GameCard(2,clubs,"ren_wang_shield.png","ren_wang_shield_equip 5 0")); //ability id, target type, target range

//toolcardses
// 0
set.push_back(new GameCard(12,diamonds,"negate.png","negate 0 0")); //ability id, target type, target range
set.push_back(new GameCard(13,clubs,"negate.png","negate 0 0")); //ability id, target type, target range
set.push_back(new GameCard(12,clubs,"negate.png","negate 0 0")); //ability id, target type, target range
set.push_back(new GameCard(11,spades,"negate.png","negate 0 0")); //ability id, target type, target range
set.push_back(new GameCard(1,spades,"duel.png","duel 1 0")); //ability id, target type, target range
set.push_back(new GameCard(1,clubs,"duel.png","duel 1 0")); //ability id, target type, target range
set.push_back(new GameCard(1,diamonds,"duel.png","duel 1 0")); //ability id, target type, target range
set.push_back(new GameCard(1,hearts,"peach_garden.png","peach_garden 0 0")); //ability id, target type, target range
set.push_back(new GameCard(11,hearts,"draw2.png","draw2 0 0")); //ability id, target type, target range
set.push_back(new GameCard(9,hearts,"draw2.png","draw2 0 0")); //ability id, target type, target range
set.push_back(new GameCard(8,hearts,"draw2.png","draw2 0 0")); //ability id, target type, target range
set.push_back(new GameCard(7,hearts,"draw2.png","draw2 0 0")); //ability id, target type, target range
set.push_back(new GameCard(12,hearts,"lightning.png","lightning 0 0")); //ability id, target type, target range
set.push_back(new GameCard(1,clubs,"lightning.png","lightning 0 0")); //ability id, target type, target range
set.push_back(new GameCard(1,hearts,"raining_arrows.png","raining_arrows 0 0")); //ability id, target type, target range
set.push_back(new GameCard(4,hearts,"harvest.png","harvest 0 0")); //ability id, target type, target range
set.push_back(new GameCard(3,hearts,"harvest.png","harvest 0 0")); //ability id, target type, target range
set.push_back(new GameCard(13,clubs,"duress.png","duress 2 0")); //ability id, target type, target range
set.push_back(new GameCard(12,clubs,"duress.png","duress 2 0")); //ability id, target type, target range
set.push_back(new GameCard(4,diamonds,"steal.png","steal 1 9")); //ability id, target type, target range
set.push_back(new GameCard(3,diamonds,"steal.png","steal 1 9")); //ability id, target type, target range
set.push_back(new GameCard(11,spades,"steal.png","steal 1 9")); //ability id, target type, target range
set.push_back(new GameCard(4,spades,"steal.png","steal 1 9")); //ability id, target type, target range
set.push_back(new GameCard(3,spades,"steal.png","steal 1 9")); //ability id, target type, target range
set.push_back(new GameCard(13,spades,"barbarian.png","barbarian 0 0")); //ability id, target type, target range
set.push_back(new GameCard(7,clubs,"barbarian.png","barbarian 0 0")); //ability id, target type, target range
set.push_back(new GameCard(7,spades,"barbarian.png","barbarian 0 0")); //ability id, target type, target range
set.push_back(new GameCard(6,hearts,"acedia.png","acedia 3 0")); //ability id, target type, target range
set.push_back(new GameCard(6,clubs,"acedia.png","acedia 3 0")); //ability id, target type, target range
set.push_back(new GameCard(6,spades,"acedia.png","acedia 3 0")); //ability id, target type, target range
set.push_back(new GameCard(12,hearts,"dismantle.png","dismantle 1 0")); //ability id, target type, target range
set.push_back(new GameCard(12,spades,"dismantle.png","dismantle 1 0")); //ability id, target type, target range
set.push_back(new GameCard(3,clubs,"dismantle.png","dismantle 1 0")); //ability id, target type, target range
set.push_back(new GameCard(4,clubs,"dismantle.png","dismantle 1 0")); //ability id, target type, target range
set.push_back(new GameCard(3,spades,"dismantle.png","dismantle 1 0")); //ability id, target type, target range
set.push_back(new GameCard(4,spades,"dismantle.png","dismantle 1 0")); //ability id, target type, target range

}

} //namespace