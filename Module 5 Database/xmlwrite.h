#pragma once

#ifndef __xmlwrite_h__

#define __xmlwrite_h__

#undef DOMDocument
#include "xmlparser.h"            //include xmlparser.h
#include <iostream>			//include input output stram
#include <stdlib.h>
#include <string>
#include <sstream>
#include <xercesc/framework/LocalFileFormatTarget.hpp>        // Required for outputing a Xerces DOMDocument

																// to the file system (Also see: XMLFormatTarget)

#include <xercesc/framework/StdOutFormatTarget.hpp>                  // Required for outputing a Xerces DOMDocument

																	// to a standard output stream (Also see: XMLFormatTarget)

#include <xercesc/dom/DOM.hpp>                                                    // Use the Document Object Model (DOM) API

#include <xercesc/util/PlatformUtils.hpp>                                  // Mandatory for using any feature of Xerces.
XERCES_CPP_NAMESPACE_USE

class xmlwrite                    //class xmlwrite

{



public:
	xercesc::DOMDocument* Doc;
	xmlwrite(xercesc::DOMDocument*);

	~xmlwrite();

	void insertSong();
	void insertArtist(int id,int artist);
	void insertAlbum(int id, int album);
	void createNewPlaylist();

	void AddSong();

	int getChildValue21(const char* parentTag1, const char* parentTag2, string parentIndex, const char* childTag, int childIndex);

	int getChildCount21(const char* parentTag, int parentIndex, const char* childTag);

	void artistupdate(const wchar_t* a);
	void albumupdate(const wchar_t* b);

private:

	void insertelement(xercesc::DOMDocument* pmyDOMDocument, string  FullFilePath);


};

#endif
