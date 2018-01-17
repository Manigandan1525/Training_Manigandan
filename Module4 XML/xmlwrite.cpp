#include "xmlwrite.h"

const int ABSOLUTE_PATH_FILENAME_PREFIX_SIZE = 0;

xmlwrite::xmlwrite(DOMDocument* doc1)
{
	Doc = doc1;		//assign doc1 to Doc
}
xmlwrite::~xmlwrite()
{
	if (Doc)
	{
		Doc->release();
	}
}

void xmlwrite::insertSong()				//insert song
{
	wstring song;
	const wchar_t* newSong;
	DOMImplementation*    DomDocImplementation = NULL;
	DOMElement * p_DataElement = NULL;				//declaring DOMElement
	DOMElement * dataElement = NULL;
	DOMText* textNode = NULL;
	DomDocImplementation = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));
	XMLCh* temp = XMLString::transcode("songs");
	DOMNodeList* list = Doc->getElementsByTagName(temp);
	XMLString::release(&temp);
	DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item(0));

	p_DataElement = Doc->createElement(L"song");			//create element
	cout << "Enter Song ID" << endl;
	wcin >> song;
	newSong = song.c_str();
	p_DataElement->setAttribute(L"id", newSong);			//set attribute
	p_RootElement->appendChild(p_DataElement);				//append data

	dataElement = Doc->createElement(L"song_name");			//create element
	cout << "Enter song name" << endl;
	wcin >> song;
	newSong = song.c_str();
	textNode = Doc->createTextNode(newSong);
	dataElement->appendChild(textNode);
	p_DataElement->appendChild(dataElement);				//append data

	dataElement = Doc->createElement(L"length");			//create element
	cout << "Enter the song length" << endl;
	wcin >> song;
	newSong = song.c_str();
	textNode = Doc->createTextNode(newSong);
	dataElement->appendChild(textNode);
	p_DataElement->appendChild(dataElement);				//append data

	dataElement = Doc->createElement(L"artist-of");			//create element
	cout << "Enter the artist name" << endl;
	wcin >> song;
	newSong = song.c_str();
	dataElement->setAttribute(L"artist_idref", newSong);		//set attribute
	p_DataElement->appendChild(dataElement);				//append data

	dataElement = Doc->createElement(L"album-of");			//create element
	cout << "Enter the album name" << endl;
	wcin >> song;
	newSong = song.c_str();
	dataElement->setAttribute(L"album_idref", newSong);			//set attribute
	p_DataElement->appendChild(dataElement);					//append data
	insertelement(Doc, "./music.xml");
}

void xmlwrite::insertArtist() {					//insert artist
	int total; 
	wstring artist;
	const wchar_t* newArtist;
	DOMImplementation*    DomDocImplementation = NULL;
	DOMElement * p_DataElement = NULL;			//declaring DOMElement
	DOMElement * dataElement = NULL;
	DOMText* textNode = NULL;
	DOMElement * NewData = NULL;
	DomDocImplementation = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));
	XMLCh* temp = XMLString::transcode("artists");
	DOMNodeList* list = Doc->getElementsByTagName(temp);
	XMLString::release(&temp);
	DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item(0));

	p_DataElement = Doc->createElement(L"artist");				//create element
	cout << "Enter Artist ID";
	wcin >> artist;
	newArtist = artist.c_str();
	p_DataElement->setAttribute(L"artist_id", newArtist);			//set attribute
	p_RootElement->appendChild(p_DataElement);					//append data

	dataElement = Doc->createElement(L"artist_name");			//create element
	cout << "Enter the artist name" << endl;
	wcin >> artist;
	newArtist = artist.c_str();
	textNode = Doc->createTextNode(newArtist);
	dataElement->appendChild(textNode);
	p_DataElement->appendChild(dataElement);					//append data

	dataElement = Doc->createElement(L"artistsong");			//create element
	p_DataElement->appendChild(dataElement);					//append data

	cout << "Enter the number of songs" << endl;
	cin >> total;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter valid number " << '\t';
			cin >> total;
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < total; i++) {
		NewData = Doc->createElement(L"song-of");
		cout << "Enter the song name" << endl;
		wcin >> artist;
		newArtist = artist.c_str();
		NewData->setAttribute(L"artistsong_idref", newArtist);		//set attribute
		dataElement->appendChild(NewData);							//append data
	}
	p_DataElement->appendChild(dataElement);					//append data
	insertelement(Doc, "./music.xml");
}

void xmlwrite::insertAlbum() {					//insert album
	int total;
	char character;
	wstring album;
	const wchar_t* newAlbum;
	DOMImplementation*    DomDocImplementation = NULL;
	DOMElement * p_DataElement = NULL;				//declaring DOMElement
	DOMElement * dataElement = NULL;	
	DOMText* textNode = NULL;
	DOMElement *  NewData = NULL;
	DomDocImplementation = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));
	XMLCh* temp = XMLString::transcode("albums");
	DOMNodeList* list = Doc->getElementsByTagName(temp);
	XMLString::release(&temp);
	DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item(0));

	p_DataElement = Doc->createElement(L"album");				//create element
	cout << "Enter Album ID";
	wcin >> album;
	newAlbum = album.c_str();
	p_DataElement->setAttribute(L"album_id", newAlbum);			//set attribute
	p_RootElement->appendChild(p_DataElement);					//append data

	dataElement = Doc->createElement(L"compilation_album");
	cout << "The album is compilation album(y/n)" << endl;
	cin >> character;
	if (character == 'y')
	{
	album = L"true";
	}
	else if(character == 'n')
	{
	album=L"false";
	}newAlbum = album.c_str();
	textNode = Doc->createTextNode(newAlbum);
	dataElement->appendChild(textNode);
	p_DataElement->appendChild(dataElement);					//append data

	dataElement = Doc->createElement(L"album_name");			//create element
	cout << "Enter the album name" << endl;
	wcin >> album;
	newAlbum = album.c_str();
	textNode = Doc->createTextNode(newAlbum);
	dataElement->appendChild(textNode);
	p_DataElement->appendChild(dataElement);

	dataElement = Doc->createElement(L"albumsong");				//create element
	p_DataElement->appendChild(dataElement);					//append data

	cout << "Enter the number of songs" << endl;
	cin >> total;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter valid number " << '\t';
			cin >> total;
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < total; i++) {
		NewData = Doc->createElement(L"song_of");				//create element
		cout << "Enter the song name" << endl;
		wcin >> album;
		newAlbum = album.c_str();
		NewData->setAttribute(L"albumsong_idref", newAlbum);		//set attribute
		dataElement->appendChild(NewData);							//append data
	}
	p_DataElement->appendChild(dataElement);						//append data
	insertelement(Doc, "./music.xml");
}

void xmlwrite::createNewPlaylist()			//create playlist
{
	int total;
	wstring playlist;
	const wchar_t* newPlaylist;
	DOMImplementation*    DomDocImplementation = NULL;
	DOMElement * p_DataElement = NULL;				//declaring DOMElement
	DOMElement * dataElement = NULL;
	DOMText* textNode = NULL;
	DOMElement * NewData = NULL;
	DomDocImplementation = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));
	XMLCh* temp = XMLString::transcode("playlist");
	DOMNodeList* list = Doc->getElementsByTagName(temp);
	XMLString::release(&temp);
	DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item(0));

	p_DataElement = Doc->createElement(L"list");				//create element
	p_RootElement->appendChild(p_DataElement);					//append data

	dataElement = Doc->createElement(L"playlist_name");
	cout << "Enter the playlist name " << endl;
	wcin >> playlist;
	newPlaylist = playlist.c_str();
	textNode = Doc->createTextNode(newPlaylist);
	dataElement->appendChild(textNode);
	p_DataElement->appendChild(dataElement);					//append data


	dataElement = Doc->createElement(L"playlist_song");				//create element
	p_DataElement->appendChild(dataElement);					//append data

	cout << "Enter the number of songs" << endl;
	cin >> total;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Enter valid number " << '\t';
			cin >> total;
		}
		else
		{
			break;
		}
	}
	for (int i = 0; i < total; i++) {
		NewData = Doc->createElement(L"song_list");					//create element
		cout << "Enter the song name;" << endl;
		wcin >> playlist;
		newPlaylist = playlist.c_str();
		NewData->setAttribute(L"songlist_idref", newPlaylist);
		dataElement->appendChild(NewData);							//append data
	}
	p_DataElement->appendChild(dataElement);						//append data

	insertelement(Doc, "./music.xml");
}


void xmlwrite::insertelement(DOMDocument* pmyDOMDocument, string FullFilePath)			//element insert to file
{
	DOMImplementation *implementation = DOMImplementationRegistry::getDOMImplementation(L"LS");
	DOMLSSerializer *serializer = ((DOMImplementationLS*)implementation)->createLSSerializer();
	if (serializer->getDomConfig()->canSetParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true))
		serializer->getDomConfig()->setParameter(XMLUni::fgDOMWRTFormatPrettyPrint, true);
	serializer->setNewLine(XMLString::transcode("\r\n"));
	XMLCh *tempFilePath = XMLString::transcode(FullFilePath.c_str());
		const int pathLen = XMLString::stringLen(tempFilePath);
	XMLCh *targetPath = (XMLCh*)XMLPlatformUtils::fgMemoryManager->allocate((pathLen + ABSOLUTE_PATH_FILENAME_PREFIX_SIZE) * sizeof(XMLCh));
		XMLString::fixURI(tempFilePath, targetPath);
	XMLFormatTarget *formatTarget = new LocalFileFormatTarget(targetPath);
	DOMLSOutput *output = ((DOMImplementationLS*)implementation)->createLSOutput();
	output->setByteStream(formatTarget);
	serializer->write(pmyDOMDocument, output);
	serializer->release();
	XMLString::release(&tempFilePath);
	delete formatTarget;
	output->release();
}
