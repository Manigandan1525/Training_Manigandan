#include "XmlParser.h"

vector<GameData> XmlParser::parser(char* buffer)			//parse xml data
{
	string name;
	xml_document<> document;
	document.parse<0>(&buffer[0]);
	xml_node<> *node = document.first_node();
	xml_node<> *node1 = node->first_node();
	name = node1->name();
	if (name == JOIN)
	{
		return parse_joingame(&document);
	}
	else if (name == CATEGORYLIST)
	{
		return parse_creategame(&document);
	}
	else if (name == GAMEINFO)
	{
		return parse_gameinfo(&document);
	}

}

vector<GameData> XmlParser::parse_joingame(xml_document<>* document)		//parse the joingame details
{
	int i=0;
	vector<GameData> data;
	vector<string> gameid;
	xml_node<>* node = document->first_node();
	xml_node<> *node1 = node->first_node(JOIN);
	xml_node<> *element = node1->first_node();
		while (element != NULL)
		{
			gameid.push_back(element->value());
			element = element->next_sibling();
		}
		i++;
		detail.set_gameid(gameid);
		data.push_back(detail);
		return data;
}

vector<GameData> XmlParser::parse_creategame(xml_document<>* document)			//parse the crate game details
{
	int i = 0,j=0;
	vector<GameData> data;
	vector<string> category;
	xml_node<> *node = document->first_node();
	xml_node<> *node1 = node->first_node(CATEGORYLIST);
	xml_node<>*element = node1->first_node();
	while (element != NULL)
	{
		category.push_back(element->value());
		element = element->next_sibling();
		i++;
	}
	detail.set_gameoption(category);
	data.push_back(detail);
	vector<string> difficulty;
	xml_node<> *node2 = node->first_node(DIFFICULTYLEVEL);
	xml_node<>*element1 = node2->first_node();
	while (element1 != NULL)
	{
	    difficulty.push_back(element1->value());
		element1 = element1->next_sibling();
		j++;
	}
	detail.set_gameoption(difficulty);
	data.push_back(detail);
	return data;
}

vector<GameData> XmlParser::parse_gameinfo(xml_document<>* document)			//parse the gameinfo details
{
	vector<GameData> data;
	vector<string> gameinfo;
	xml_node<> *node = document->first_node();
	xml_node<> *node1 = node->first_node(GAMEINFO);
	xml_node<> *element = node1->first_node(GAMEID);
	string value = element->value();
	detail.set_usergameid(value);
	element = node1->first_node(WORDS);
	detail.set_words(element->value());
	element = node1->first_node(REMAININGGUESS);
	detail.set_remainingguess(element->value());
	element = node1->first_node(WRONGGUESS);
	detail.set_wrongguess(element->value());
	element = node1->first_node(RESULT);
	detail.set_result(element->value());
	element = node1->first_node(CHANCE);
	detail.set_chance(element->value());
	data.push_back(detail);
	return data;
}

string XmlParser::receive_data(char* buffer)				//parse receive data
{
	string name;
	xml_document<> doc;
	doc.parse<0>(&buffer[0]);
	xml_node<> *node = doc.first_node(HANGMAN);
	xml_node<> *node1 = node->first_node();
	name = node1->name();
	if (name == JOIN)
	{
		return JOIN;
	}
	else if (name == CATEGORYLIST)
	{
		return CATEGORYLIST;
	}
	else if (name == GAMEINFO)
	{
		return GAMEINFO;
	}

}