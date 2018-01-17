#pragma once

#ifndef __xmlparser_h__
#define __xmlparser_h__

#include<iostream>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <string>

using namespace std;
using namespace xercesc;

class xmlparser
{
	DOMDocument* m_doc;
public:
	xmlparser(const char* xmlfile);
	~xmlparser();
	DOMDocument* getDocument();
	string getChildValue(const char* parentTag, int parentIndex,
		const char* childTag, int childIndex);
	string getChildAttribute(const char* parentTag,
		int parentIndex, const char* childTag, int childIndex,
		
		const char* attributeTag);
	string getElement(const char* parentTag, int parentIndex, const char* childTag, int childIndex, const char* attributeTag,
		const char* newList1, const char* newList2, int length, const char* attributeTag1, const char* attributeTag2 );
	int getRootElementCount(const char* rootElementTag);
	int getChildCount(const char* parentTag, int parentIndex,
		const char* childTag);
	void displaySongs();
	void displayArtist();
	void displayAlbum();
	void displayPlaylist();
	xmlparser(DOMDocument*);
private:
	xmlparser();
	xmlparser(const xmlparser&);
	string value;
};
#endif