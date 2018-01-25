#pragma once

#ifndef __xmlparser_h__
#define __xmlparser_h__
#include <string>
#include <iostream>			//include input output stram
#include <sstream>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#ifndef _MSXML_LIBRARY_DEFINED_
#define _MSXML_LIBRARY_DEFINED_
#endif
using namespace std;
using namespace xercesc_3_2;
XERCES_CPP_NAMESPACE_USE
class xmlparser
{
public:
	xercesc_3_2::DOMDocument* m_doc;
	xmlparser(const char* xmlfile);
	~xmlparser();
	xercesc::DOMDocument* getDocument();
	string getChildValue(const char* parentTag, int parentIndex,
		const char* childTag, int childIndex);
	string getChildValue1(const char* parentTag,const char* parentTag1, int parentIndex,
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
	void display_singlesong();
	void display_singleartist();
	void display_singlealbum();
	void display_particularplaylist();
	xmlparser(xercesc::DOMDocument*);
private:
	xmlparser();
	xmlparser(const xmlparser&);
	string value;
};
#endif