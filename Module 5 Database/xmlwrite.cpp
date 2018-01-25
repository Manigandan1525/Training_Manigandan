#include "xmlwrite.h"
const int ABSOLUTE_PATH_FILENAME_PREFIX_SIZE = 0;

xmlwrite::xmlwrite(DOMDocument* doc1)
{
	Doc = doc1;          //assign doc1 to Doc
}

xmlwrite::~xmlwrite()
{
	if (Doc)
	{
		Doc->release();
	}
}

void xmlwrite::insertSong()                     //insert song
{
	wstring song;
	const wchar_t* newSong;
	DOMImplementation*    DomDocImplementation = NULL;
	DOMElement * p_DataElement = NULL;                     //declaring DOMElement
	DOMElement * dataElement = NULL;
	DOMText* textNode = NULL;
	DomDocImplementation = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));

	XMLCh* temp = XMLString::transcode("songs");

	DOMNodeList* list = Doc->getElementsByTagName(temp);

	XMLString::release(&temp);

	DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item(0));



	p_DataElement = Doc->createElement(L"song");                  //create element

	cout << "Enter Song ID" << endl;

	wcin >> song;

	newSong = song.c_str();

	p_DataElement->setAttribute(L"id", newSong);                  //set attribute

	p_RootElement->appendChild(p_DataElement);                           //append data



	dataElement = Doc->createElement(L"song_name");               //create element

	cout << "Enter song name" << endl;

	wcin >> song;

	newSong = song.c_str();

	textNode = Doc->createTextNode(newSong);

	dataElement->appendChild(textNode);

	p_DataElement->appendChild(dataElement);                      //append data



	dataElement = Doc->createElement(L"length");                  //create element

	cout << "Enter the song length" << endl;

	wcin >> song;

	newSong = song.c_str();

	textNode = Doc->createTextNode(newSong);

	dataElement->appendChild(textNode);

	p_DataElement->appendChild(dataElement);                      //append data



	dataElement = Doc->createElement(L"artist");                  //create element

	cout << "Enter the existing artist id" << endl;

	wcin >> song;

	newSong = song.c_str();

	dataElement->setAttribute(L"idref", newSong);          //set attribute

	p_DataElement->appendChild(dataElement);                      //append data



	dataElement = Doc->createElement(L"album");                   //create element

	cout << "Enter the existing album id" << endl;

	wcin >> song;

	newSong = song.c_str();

	dataElement->setAttribute(L"idref", newSong);                 //set attribute

	p_DataElement->appendChild(dataElement);                             //append data

	insertelement(Doc, "./music.xml");

}

void xmlwrite::createNewPlaylist()              //create playlist

{

	int total;

	wstring playlist;

	const wchar_t* newPlaylist;

	DOMImplementation*    DomDocImplementation = NULL;

	DOMElement * p_DataElement = NULL;                     //declaring DOMElement

	DOMElement * dataElement = NULL;

	DOMText* textNode = NULL;

	DOMElement * NewData = NULL;

	DomDocImplementation = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));

	XMLCh* temp = XMLString::transcode("playlist");

	DOMNodeList* list = Doc->getElementsByTagName(temp);

	XMLString::release(&temp);

	DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item(0));

	p_DataElement = Doc->createElement(L"list");                         //create element

	p_RootElement->appendChild(p_DataElement);                                 //append data



	dataElement = Doc->createElement(L"playlist_name");

	cout << "Enter the playlist name " << endl;

	wcin >> playlist;

	newPlaylist = playlist.c_str();

	textNode = Doc->createTextNode(newPlaylist);

	dataElement->appendChild(textNode);

	p_DataElement->appendChild(dataElement);                             //append data


	dataElement = Doc->createElement(L"playlist_song");                        //create element

	p_DataElement->appendChild(dataElement);                             //append data



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

		NewData = Doc->createElement(L"song_of_playlist");                               //create element

		cout << "Enter the existing song name" << endl;
		wcin >> playlist;
		string list(playlist.begin(), playlist.end());

		int value=getChildValue21("songs", "song", list, "song_name", 0);
		if (value == -1)
		{
			cout << "you entered wrong song name" << endl;
			--i;
			continue;
		}
		string songid = 's' + to_string(value + 1);
		wstring newsong(songid.begin(), songid.end());
		newPlaylist = newsong.c_str();

		NewData->setAttribute(L"idref", newPlaylist);

		dataElement->appendChild(NewData);                                         //append data
	}

	p_DataElement->appendChild(dataElement);                                   //append data

	insertelement(Doc, "./music.xml");
	cout << "Playlist create successfully!!" << endl;

}


void xmlwrite::insertelement(DOMDocument* pmyDOMDocument, string FullFilePath)                  //element insert to file

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



int xmlwrite::getChildCount21(const char* parentTag, int parentIndex, const char* childTag)

{

	XMLCh* temp = XMLString::transcode(parentTag);

	DOMNodeList* list = Doc->getElementsByTagName(temp);

	XMLString::release(&temp);





	DOMElement* parent = dynamic_cast<DOMElement*>(list->item(parentIndex));

	DOMNodeList* childList = parent->getElementsByTagName(XMLString::transcode(childTag));

	return (int)childList->getLength();

}



int xmlwrite::getChildValue21(const char* parentTag1, const char* parentTag2, string parentIndex, const char* childTag, int childIndex) {                        //get child value

	XMLCh* temp = XMLString::transcode(parentTag2);

	DOMNodeList* list = Doc->getElementsByTagName(temp);

	XMLString::release(&temp);

	for (int i = 0; i < getChildCount21(parentTag1, 0, parentTag2); i++)

	{

		DOMElement* parent = dynamic_cast<DOMElement*>(list->item(i));

		DOMElement* child =

			dynamic_cast<DOMElement*>(parent->getElementsByTagName(XMLString::transcode(childTag))->item(childIndex));

		string value;

		if (child) {

			char* temp2 = XMLString::transcode(child->getTextContent());

			value = temp2;

			XMLString::release(&temp2);

			if (value == parentIndex)

			{

				return i;

			}

		}

		else {

			value = "";



		}



	}

	return -1;

}

void xmlwrite::insertArtist(int song_id,int artist)
{
	wstring songartist;
	int artist_id;
	if (artist != -1)

	{
		const wchar_t* newArtist;
		const wchar_t* newArtist1;
		DOMImplementation*    DomDocImplementation = NULL;

		DOMElement * p_DataElement = NULL;                     //declaring DOMElement

		DOMElement * dataElement = NULL;

		DOMText* textNode = NULL;

		DOMElement * NewData = NULL;

		DomDocImplementation = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));

		XMLCh* temp = XMLString::transcode("artistsong");

		DOMNodeList* list = Doc->getElementsByTagName(temp);

		XMLString::release(&temp);

		DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item(artist));

		p_DataElement = Doc->createElement(L"song_of_artist");               //create element


		string song;

		song = 's' + to_string(song_id);


		wstring wss(song.begin(), song.end());

		newArtist = wss.c_str();

		p_DataElement->setAttribute(L"idref", newArtist);               //set attribute

		p_RootElement->appendChild(p_DataElement);

		insertelement(Doc, "./music.xml");
		string s = "art" + to_string(artist + 1);
		wstring wss1(s.begin(), s.end());
		newArtist1 = wss1.c_str();
		artistupdate(newArtist1);

	}

	else if (artist == -1)

	{

		wstring artist;

		const wchar_t* newArtist;
		const wchar_t* newArtist1;

		DOMImplementation*    DomDocImplementation = NULL;

		DOMElement * p_DataElement = NULL;              //declaring DOMElement

		DOMElement * dataElement = NULL;

		DOMText* textNode = NULL;

		DOMElement * NewData = NULL;

		DomDocImplementation = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));

		XMLCh* temp = XMLString::transcode("artists");

		DOMNodeList* list = Doc->getElementsByTagName(temp);

		XMLString::release(&temp);

		DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item(0));



		p_DataElement = Doc->createElement(L"artist");                       //create element

		string s;
		artist_id = getChildCount21("artists", 0, "artist") + 1;
		s = "art" + to_string(artist_id);

		wstring was(s.begin(), s.end());

		newArtist = was.c_str();
		newArtist1 = newArtist;
		p_DataElement->setAttribute(L"id", newArtist);                //set attribute

		p_RootElement->appendChild(p_DataElement);                                 //append data



		dataElement = Doc->createElement(L"artist_name");                    //create element


		newArtist = songartist.c_str();

		textNode = Doc->createTextNode(newArtist);

		dataElement->appendChild(textNode);

		p_DataElement->appendChild(dataElement);                             //append data



		dataElement = Doc->createElement(L"artistsong");                     //create element

		p_DataElement->appendChild(dataElement);
		for (int i = 0; i < 1; i++)
		{
			NewData = Doc->createElement(L"song_of_artist");
			string song1_id;
			song1_id = 's' + to_string(song_id);
	
			wstring wss(song1_id.begin(), song1_id.end());
			newArtist = wss.c_str();
			NewData->setAttribute(L"idref", newArtist);
			dataElement->appendChild(NewData);//set attribute
		}
		p_DataElement->appendChild(dataElement);
		insertelement(Doc, "./music.xml");
		artistupdate(newArtist1);
	}

}

void xmlwrite::insertAlbum(int song_id,int album)
{
	wstring songalbum;
	if (album != -1)

	{

		const wchar_t* newAlbum;
		const wchar_t* newAlbum1;
		DOMImplementation*    DomDocImplementation = NULL;

		DOMElement * p_DataElement = NULL;                     //declaring DOMElement

		DOMElement * dataElement = NULL;

		DOMText* textNode = NULL;

		DOMElement * NewData = NULL;

		DomDocImplementation = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));

		XMLCh* temp = XMLString::transcode("albumsong");

		DOMNodeList* list = Doc->getElementsByTagName(temp);

		XMLString::release(&temp);

		DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item(album));

		p_DataElement = Doc->createElement(L"song_of_album");               //create element

		string song1_id;

		song1_id = 's' + to_string(song_id);


		wstring wss(song1_id.begin(), song1_id.end());

		newAlbum = wss.c_str();

		p_DataElement->setAttribute(L"idref", newAlbum);               //set attribute

		p_RootElement->appendChild(p_DataElement);

		insertelement(Doc, "./music.xml");
		string s = "alb" + to_string(album + 1);
		wstring wss1(s.begin(), s.end());
		newAlbum1 = wss1.c_str();
		albumupdate(newAlbum1);


	}

	else if (album == -1)

	{

		wstring album;
		int album_id;
		string s1;
		const wchar_t* newAlbum;
		const wchar_t* newAlbum1;
		char character;
		DOMImplementation*    DomDocImplementation = NULL;

		DOMElement * p_DataElement = NULL;              //declaring DOMElement

		DOMElement * dataElement = NULL;

		DOMText* textNode = NULL;

		DOMElement* NewData = NULL;

		DomDocImplementation = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));

		XMLCh* temp = XMLString::transcode("albums");

		DOMNodeList* list = Doc->getElementsByTagName(temp);

		XMLString::release(&temp);

		DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item(0));


		p_DataElement = Doc->createElement(L"album");                       //create element

		album_id = getChildCount21("albums", 0, "album") + 1;
		s1 = "alb" + to_string(album_id);

		wstring was(s1.begin(), s1.end());

		newAlbum = was.c_str();
		newAlbum1 = newAlbum;
		p_DataElement->setAttribute(L"id", newAlbum);                //set attribute

		p_RootElement->appendChild(p_DataElement);                                 //append data


		dataElement = Doc->createElement(L"compilation_album");

		cout << "The album is compilation album(y/n)" << endl;

		cin >> character;

		if (character == 'y')

		{

			album = L"true";

		}

		else if (character == 'n')

		{

			album = L"false";

		}newAlbum = album.c_str();

		textNode = Doc->createTextNode(newAlbum);

		dataElement->appendChild(textNode);

		p_DataElement->appendChild(dataElement);                             //append data


		dataElement = Doc->createElement(L"album_name");                    //create element

		newAlbum = songalbum.c_str();

		textNode = Doc->createTextNode(newAlbum);

		dataElement->appendChild(textNode);

		p_DataElement->appendChild(dataElement);                             //append data


		dataElement = Doc->createElement(L"albumsong");                     //create element

		p_DataElement->appendChild(dataElement);                             //append data
		for (int i = 0; i < 1; i++)
		{
			NewData = Doc->createElement(L"song_of_album");
			string song1_id;

			song1_id = 's' + to_string(song_id);


			wstring wss(song1_id.begin(), song1_id.end());


			newAlbum = wss.c_str();

			NewData->setAttribute(L"idref", newAlbum);                 //set attribute

			dataElement->appendChild(NewData);
		}
		p_DataElement->appendChild(dataElement);
		insertelement(Doc, "./music.xml");
		albumupdate(newAlbum1);

	}
}
void xmlwrite::AddSong()

{

	int artist, album;
	wstring songartist;
	wstring songalbum;
	wstring newsong;
	int song_id;

	
	cout << "Enter song name: " << endl;

	getline(wcin >> ws, newsong);

	string song(newsong.begin(), newsong.end());


	artist = getChildValue21("songs", "song", song, "song_name", 0);

	if (artist != -1)

	{

		cout << "This song already exist, so it can't be insert" << endl;

	}

	else if (artist == -1)

	{

		wstring song;
		const wchar_t* newSong;

		DOMImplementation*    DomDocImplementation = NULL;

		DOMElement * p_DataElement = NULL;                     //declaring DOMElement

		DOMElement * dataElement = NULL;

		DOMText* textNode = NULL;

		DomDocImplementation = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));

		XMLCh* temp = XMLString::transcode("songs");

		DOMNodeList* list = Doc->getElementsByTagName(temp);

		XMLString::release(&temp);

		DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item(0));



		p_DataElement = Doc->createElement(L"song");                  //create element

		song_id = getChildCount21("songs", 0, "song") + 1;
		string song1_id;

		song1_id = 's' + to_string(song_id);

		wstring song1(song1_id.begin(), song1_id.end());

		newSong = song1.c_str();

		p_DataElement->setAttribute(L"id", newSong);                  //set attribute

		p_RootElement->appendChild(p_DataElement);



		dataElement = Doc->createElement(L"song_name");               //create element


		newSong = newsong.c_str();

		textNode = Doc->createTextNode(newSong);

		dataElement->appendChild(textNode);

		p_DataElement->appendChild(dataElement);                      //append data



		dataElement = Doc->createElement(L"length");                  //create element

		cout << "Enter the song length" << endl;

		wcin >> song;

		newSong = song.c_str();

		textNode = Doc->createTextNode(newSong);

		dataElement->appendChild(textNode);

		p_DataElement->appendChild(dataElement);                      //append data


		cout << "Enter artist name" << endl;


		wcin >> songartist;

		newSong = songartist.c_str();

		textNode = Doc->createTextNode(newSong);

		cout << "Enter album name" << endl;

		wcin >> songalbum;

		newSong = songalbum.c_str();

		textNode = Doc->createTextNode(newSong);


		string alb(songalbum.begin(), songalbum.end());
		string art(songartist.begin(), songartist.end());


		artist = getChildValue21("artists", "artist", art, "artist_name", 0);
		album = getChildValue21("albums", "album", alb, "album_name", 0);
		insertelement(Doc, "./music.xml");
	}

	insertArtist(song_id, artist);
	insertAlbum(song_id, album);
	cout << "Song Added succesfully!!" << endl;
}
void xmlwrite::artistupdate(const wchar_t* id)
	{

		

		const wchar_t* newArtist1;

		DOMImplementation*    DomDocImplementation1 = NULL;

		DOMElement * p_DataElement = NULL;              //declaring DOMElement

		DOMElement * dataElement = NULL;

		DOMText* textNode = NULL;

		DOMElement * NewData = NULL;

		DomDocImplementation1 = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));

		XMLCh* temp1 = XMLString::transcode("song");

		DOMNodeList* list = Doc->getElementsByTagName(temp1);

		XMLString::release(&temp1);

		DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item((getChildCount21("songs",0,"song")-1)));
		dataElement = Doc->createElement(L"songartist");

		string s;

		s = "art" + to_string(getChildCount21("artists", 0, "artist") );

		wstring was(s.begin(), s.end());

		newArtist1 = was.c_str();

		dataElement->setAttribute(L"idref", id);                     //set attribute

		p_RootElement->appendChild(dataElement);                             //append data

		insertelement(Doc, "./music.xml");
	}

		void xmlwrite::albumupdate(const wchar_t* id)
	{

	

		const wchar_t* newAlbum1;

		DOMImplementation*    DomDocImplementation1 = NULL;

		DOMElement * p_DataElement = NULL;              //declaring DOMElement

		DOMElement * dataElement = NULL;

		DOMText* textNode = NULL;

		DOMElement * NewData = NULL;

		DomDocImplementation1 = DOMImplementationRegistry::getDOMImplementation(XMLString::transcode("core"));

		XMLCh* temp1 = XMLString::transcode("song");

		DOMNodeList* list = Doc->getElementsByTagName(temp1);

		XMLString::release(&temp1);

		DOMElement* p_RootElement = dynamic_cast<DOMElement*>(list->item(getChildCount21("songs", 0, "song")-1));

		dataElement = Doc->createElement(L"songalbum");

		string data;

		data = "alb" + to_string(getChildCount21("albums", 0, "album"));

		wstring alb(data.begin(), data.end());

		newAlbum1 = alb.c_str();

		dataElement->setAttribute(L"idref", id);                     //set attribute

		p_RootElement->appendChild(dataElement);                             //append data

		insertelement(Doc, "./music.xml");
	}


	