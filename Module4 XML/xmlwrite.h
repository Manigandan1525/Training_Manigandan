#pragma once
#ifndef __xmlwrite_h__
#define __xmlwrite_h__

#include "xmlparser.h"		//include xmlparser.h
#include <xercesc/framework/LocalFileFormatTarget.hpp>		// Required for outputing a Xerces DOMDocument
															// to the file system (Also see: XMLFormatTarget)
#include <xercesc/framework/StdOutFormatTarget.hpp>			// Required for outputing a Xerces DOMDocument
															// to a standard output stream (Also see: XMLFormatTarget)
#include <xercesc/dom/DOM.hpp>								// Use the Document Object Model (DOM) API
#include <xercesc/util/PlatformUtils.hpp>					// Mandatory for using any feature of Xerces.
#include <sstream>
#include <string>
XERCES_CPP_NAMESPACE_USE
class xmlwrite			//class xmlwrite
{
private:
	void insertelement(DOMDocument* pmyDOMDocument, string  FullFilePath);
	DOMDocument* Doc;
public:
	xmlwrite(DOMDocument*);
	~xmlwrite();
	void insertSong();
	void insertArtist();
	void insertAlbum();
	void createNewPlaylist();
};
#endif