#include "xmlparser.h"

XercesDOMParser*   parser = NULL;

xmlparser::xmlparser(const char* xmlfile) : m_doc(NULL)
	 {
			XMLPlatformUtils::Initialize();				
			parser = new XercesDOMParser();			//Dom parser
			parser->parse(xmlfile);
			m_doc = parser->adoptDocument();
	 }
xmlparser::xmlparser(DOMDocument* doc1)
 {
	 m_doc = doc1;
 }
xmlparser::~xmlparser()
	 {
	      if (m_doc) m_doc->release();
	 }
DOMDocument* xmlparser::getDocument()
 {
	 return m_doc;
 }

string xmlparser::getChildValue(const char* parentTag, int parentIndex, const char* childTag, int childIndex)	  {				//get child value
	  	XMLCh* temp = XMLString::transcode(parentTag);
	 	DOMNodeList* list = m_doc->getElementsByTagName(temp);
	  	XMLString::release(&temp);
	
		 	DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
		DOMElement* child =
		         dynamic_cast<DOMElement*>(parent->getElementsByTagName(XMLString::transcode(childTag))->item(childIndex));
	  	string value;
	 	if (child) {
		 		char* temp2 = XMLString::transcode(child->getTextContent());
		 		value = temp2;
		         XMLString::release(&temp2);
		
	 }
	 	else {
		 		value = "";
		
	 }
	 	return value;
	  }

 string xmlparser::getChildAttribute(const char* parentTag, int parentIndex, const char* childTag, int childIndex,		//get child attribute
	                                          const char* attributeTag)
 {
	 XMLCh* temp = XMLString::transcode(parentTag); 

	DOMNodeList* list = m_doc->getElementsByTagName(temp);
	 	XMLString::release(&temp);
	
	
	 	DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
 	DOMElement* child =
		         dynamic_cast<DOMElement*>(parent->getElementsByTagName(XMLString::transcode(childTag))->item(childIndex));
		string value;

		
	 	if (child) {
		        temp = XMLString::transcode(attributeTag);
			
		 		char* temp2 = XMLString::transcode(child->getAttribute(temp));
		 		value = temp2;
		        XMLString::release(&temp2);
	
	 }
	  	else {
		  		value = "";
		 
	 }

	  	return value;
	  }

 string xmlparser::getElement(const char* parentTag, int parentIndex, const char* childTag, int childIndex, const char* attributeTag,     //get element deatails
	 const char* attributeTag2, const char* parentTag2, int length, const char* parent, const char* attributeTag3)
 {
	 int i = 0;
	 XMLCh* temp = XMLString::transcode(parentTag);
	 string new_value, value1;
	 DOMNodeList* list = m_doc->getElementsByTagName(temp);
	 XMLString::release(&temp);

	 
	 DOMElement* paren = dynamic_cast<DOMElement*>(list->item(parentIndex));
	 DOMElement* child =
		 dynamic_cast<DOMElement*>(paren->getElementsByTagName(XMLString::transcode(childTag))->item(childIndex));
	 string value;
	 if (child) {
		 temp = XMLString::transcode(attributeTag);

		 char* temp2 = XMLString::transcode(child->getAttribute(temp));

		 value = temp2;
		 XMLString::release(&temp2);
	 }
	 else {
		 value = "";
	 }
	 XMLCh* new_temp1 = XMLString::transcode(parentTag2);

	 DOMNodeList* list1 = m_doc->getElementsByTagName(new_temp1);
	 XMLString::release(&new_temp1);
	 for (i = 0; i < length; i++)
	 {
		 DOMElement* var = dynamic_cast<DOMElement*>(list1->item(0));
		 DOMElement* child1 =
			 dynamic_cast<DOMElement*>(var->getElementsByTagName(XMLString::transcode(parent))->item(i));
		 if (child1) {
			 XMLCh* new_temp1 = XMLString::transcode((attributeTag2));
			 char* temp11 = XMLString::transcode(child1->getAttribute(new_temp1));
			 value1 = temp11;
			 XMLString::release(&temp11);
			 if (value == value1)
			 {
				 DOMElement* child2 =
					 dynamic_cast<DOMElement*>(var->getElementsByTagName(XMLString::transcode(attributeTag3))->item(i));
				 string new_value;
				 if (child2) {
					 char* new_temp2 = XMLString::transcode(child2->getTextContent());
					 new_value = new_temp2;
					 XMLString::release(&new_temp2);
					 return new_value;
					 XMLString::release(&new_temp2);
				 }
			 }
		 }
	 }
		 return new_value;
 }
	

 int xmlparser::getRootElementCount(const char* rootElementTag)				//get element count
	  {
	  	DOMNodeList* list = m_doc->getElementsByTagName(XMLString::transcode(rootElementTag));
	  	return (int)list->getLength();
	  }
 

 int xmlparser::getChildCount(const char* parentTag, int parentIndex, const char* childTag)
	  {
	  	XMLCh* temp = XMLString::transcode(parentTag);
	  	DOMNodeList* list = m_doc->getElementsByTagName(temp);
	  	XMLString::release(&temp);
	 

		  	DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));
	  	DOMNodeList* childList = parent->getElementsByTagName(XMLString::transcode(childTag));
	      return (int)childList->getLength();
	  }

 void xmlparser::displaySongs()				//display song details
 {
	 for (int i = 0; i < getChildCount("songs", 0, "song"); i++)
	 {
		 value = getChildValue("song", i, "song_name", 0);
		 cout << "Song Name     " << value.c_str() << endl;
		 value = getChildValue("song", i, "length", 0);
		 cout << "Song Length    " << value.c_str() << endl;
		 value = getElement("songs", 0, "artist-of", i, "artist_idref",
			 "artist_id", "artists",getChildCount("artists", 0, "artist"), "artist", "artist_name");
		 cout << "artist   " << value.c_str() << endl;
		 value = getElement("songs", 0, "album-of", i, "album_idref",
			 "album_id", "albums", getChildCount("albums", 0, "album"), "album", "album_name");
		 cout << "album   " << value.c_str() << endl;
	 }
 }
 void xmlparser::displayArtist()			//display artist details
 {
	 for (int i = 0; i <getChildCount("artists", 0, "artist"); i++)
	 {
		 value = getChildValue("artist", i, "artist_name", 0);
		 cout << "Artist Name      " << value.c_str() << endl;
		 for (int j = 0; j < getChildCount("artist", i, "song-of"); j++)
		 {
			 value = getElement("artist", i, "song-of", j, "artistsong_idref",
				 "id", "songs", getChildCount("songs", 0, "song"), "song", "song_name");
			 cout << "song   " << value.c_str() << endl;
		 }
	 }
 }
 void xmlparser::displayAlbum()			//display song albums details
 {
	 for (int i = 0; i <getChildCount("albums", 0, "album"); i++)
	 {
		 value = getChildValue("album", i, "album_name", 0);
		 cout << "Albums Name      " << value.c_str() << endl;
		 for (int j = 0; j < getChildCount("album", i, "song_of"); j++)
		 {
			 value = getElement("album", i, "song_of", j, "albumsong_idref",
				 "id", "songs",getChildCount("songs", 0, "song"), "song", "song_name");
			 cout << "song   " << value.c_str() << endl;
		 }
	 }
 }
 void xmlparser::displayPlaylist()			//display the playlist details
 {
	 for (int i = 0; i < getChildCount("playlist", 0, "list"); i++)
	 {
		 value = getChildValue("list", i, "playlist_name", 0);
		 cout << "playlist Name      " << value.c_str() << endl;
		 for (int j = 0; j < getChildCount("list", i, "song_list"); j++)
		 {
			 value = getElement("list", i, "song_list", j, "songlist_idref",
				 "id", "songs", getChildCount("songs", 0, "song"), "song", "song_name");
			 cout << "song   " << value.c_str() << endl;
		 }
	 }
 }