#pragma once

 #include <iostream>			//include input output stram
 #include <stdlib.h>
 #include <string>
 #include "xmlparser.h"
#include "xmlwrite.h"
#include <sstream>
using namespace std;
 void main()
 {

		 xmlparser* doc = new xmlparser("music.xml");
		 DOMDocument* Doc1 = doc->getDocument();
		 xmlwrite* doc1 = new xmlwrite(Doc1);
		 int value1,value2;						//variable declaration
		 int choice=0,option1=0,option2=0;
		 int value=1;
		 if (doc)
		 {
			 do
			 {
				 value1 = 1;
				 value2 = 1;
				 cout << "\n"<<"Enter option:" << endl;
				 cout << "1. insert " << endl;
				 cout << "2. display " << endl;
				 cout << "3.exit" << endl;
				 cin >> choice;

				 if (cin.fail())
				 {
					 cin.clear();
					 cin.ignore(numeric_limits<streamsize>::max(), '\n');
					 cout << "Enter valid type " << '\t';
					 continue;
				 }
				switch (choice)					//using switch case
				 {
				case 1:
				 {
					 while (value1)				//using while loop
					 {
						 cout <<"\n"<< "Enter option:" << endl;
						 cout << "1. insert song" << endl;
						 cout << "2. insert artist " << endl;
						 cout << "3. insert album" << endl;
						 cout << "4. Add playlist " << endl;
						 cout << "5.exit" << endl;
						 cin >> option1;
						 if (cin.fail())
						 {
							 cin.clear();
							 cin.ignore(numeric_limits<streamsize>::max(), '\n');
							 cout << "Enter valid type " << '\t';
							 continue;
						 }
						 switch (option1)
						 {
						 case 1:doc1->insertSong();
							 break;

						 case 2:doc1->insertArtist();
							 break;
						 case 3:doc1->insertAlbum();
							 break;
						 case 4:doc1->createNewPlaylist();
							 break;
						 case 5:
							 value1 = 0;
							 break;
						 default:
							 cout << "Enter valid option " << endl;
							 break;
						 }
					 }
				 }
					 break;
				 case 2:
				 {
					  xmlparser* doc = new xmlparser(Doc1);
					 while (value2)						//using while loop
					 {
						 cout <<"\n"<< "Enter option:" << endl;
						 cout << "1. display song" << endl;
						 cout << "2. display artist " << endl;
						 cout << "3. display album" << endl;
						 cout << "4. display playlist " << endl;
						 cout << "5.exit" << endl;
						 cin >> option2;
						 if (cin.fail())
						 {
							 cin.clear();
							 cin.ignore(numeric_limits<streamsize>::max(), '\n');
							 cout << "Enter valid type" << '\t';
							 continue;
						 }
						 switch (option2)		//using switch case
						 {
						 case 1:
							 doc->displaySongs();
							 break;
						 case 2:
							 doc->displayArtist();
							 break;
						 case 3:
							 doc->displayAlbum();
							 break;
						 case 4:
							 doc->displayPlaylist();
							 break;
						 case 5:
							 value2 = 0;
							 break;
						 default:
							 cout << "Enter valid option " << endl;
							 break;
						 }
					 }
				 }
					 break;
				 
				 case 3:
					 value = 0;
					 break;
				 default:
					 cout << "Enter valid option " << endl;
					 break;
				 }
			} while (value);		//using do-while loop
		 }	 delete doc;
		 cin.get();
		 cin.ignore(1000, '\n');
}








































/*



for (int i = 0; i < doc->getChildCount("songs", 0, "song"); i++)
{
	value = doc->getChildValue("song", i, "song_name", 0);
	cout << "Song Name     " << value.c_str() << endl;
	value = doc->getChildValue("song", i, "length", 0);
	cout << "Song Length    " << value.c_str() << endl;
	value = doc->getElement("songs", 0, "artist-of", i, "artist_idref",
		"artist_id", "artists", doc->getChildCount("artists", 0, "artist"), "artist", "artist_name");
	cout << "artist   " << value.c_str() << endl;
	value = doc->getElement("songs", 0, "album-of", i, "album_idref",
		"album_id", "albums", doc->getChildCount("albums", 0, "album"), "album", "album_name");
	cout << "album   " << value.c_str() << endl;
}
for (int i = 0; i < doc->getChildCount("artists", 0, "artist"); i++)
{
	value = doc->getChildValue("artist", i, "artist_name", 0);
	cout << "Artist Name      " << value.c_str() << endl;
	for (int j = 0; j < doc->getChildCount("artist", i, "song-of"); j++)
	{
		value = doc->getElement("artist", i, "song-of", j, "artistsong_idref",
			"id", "songs", doc->getChildCount("songs", 0, "song"), "song", "song_name");
		cout << "song   " << value.c_str() << endl;
	}
}
for (int i = 0; i < doc->getChildCount("albums", 0, "album"); i++)
{
	value = doc->getChildValue("album", i, "album_name", 0);
	cout << "Albums Name      " << value.c_str() << endl;
	for (int j = 0; j < doc->getChildCount("album", i, "song_of"); j++)
	{
		value = doc->getElement("album", i, "song_of", j, "albumsong_idref",
			"id", "songs", doc->getChildCount("songs", 0, "song"), "song", "song_name");
		cout << "song   " << value.c_str() << endl;
	}
}
for (int i = 0; i < doc->getChildCount("playlist", 0, "list"); i++)
{
	value = doc->getChildValue("list", i, "playlist_name", 0);
	cout << "playlist Name      " << value.c_str() << endl;
	for (int j = 0; j < doc->getChildCount("list", i, "song_list"); j++)
	{
		value = doc->getElement("list", i, "song_list", j, "songlist_idref",
			"id", "songs", doc->getChildCount("songs", 0, "song"), "song", "song_name");
		cout << "song   " << value.c_str() << endl;
	}
}
		 } while (1);*/

		 /* for (int i = 0; i < doc->getChildCount("songs", 0, "song"); i++) {
		 // printf("Book %d\n", i + 1);
		 value = doc->getChildAttribute("bookstore", 0, "book", i, "category");
		 printf("book category   - %s\n", value.c_str());
		 value = doc->getChildValue("book", i, "title", 0);
		 printf("book title      - %s\n", value.c_str());
		 value = doc->getChildAttribute("book", i, "title", 0, "lang");
		 printf("book title lang - %s\n", value.c_str());
		 value = doc->getChildValue("book", i, "author", 0);
		 printf("book author     - %s\n", value.c_str());
		 value = doc->getChildValue("book", i, "year", 0);
		 printf("book year       - %s\n", value.c_str());
		 value = doc->getChildValue("book", i, "price", 0);
		 printf("book price      - %s\n", value.c_str());*/
		 // doc = load("filename.xml")
		 // doc.appendChild(myNode)
		 // save(doc, "filename.xml")
		 // addNode("filename.xml, myNode);
