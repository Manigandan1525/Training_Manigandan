#pragma once
#include "sql_database.h"
#include "xmlwrite.h"
#include "xmlparser.h"
using namespace std;

 int main()
 {

		 xmlparser* doc = new xmlparser("music.xml");
		 xercesc::DOMDocument* Doc1 = doc->getDocument();
		 xmlwrite* doc1 = new xmlwrite(Doc1);
		 sql_database data;
		 int value1=1,value2=1;						//variable declaration
		 int choice=0,option1=0,option2=0;
		 int value=1,option,option3,option4,option5,option6,value3=1;
		 int new_value1 = 1, new_value2 = 1,new_value3=1,new_value4=1;
		 do
		 {
		 cout << "Enter your option:" << endl;
		 cout << "1. XML file" << endl;
		 cout << "2. SQL server database " << endl;
		 cout << "3. Exit" << endl;
		 cin >> option;
		 switch (option)
		 {
		 case 1:
		 {

			 if (doc)
			 {
				 do
				 {
					 value1 = 1;
					 value2 = 1;
					 cout << "\n" << "Enter option:" << endl;
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
							 cout << "\n" << "Enter option:" << endl;
							 cout << "1. insert song" << endl;
							 cout << "2. Add playlist " << endl;
							 cout << "3.exit" << endl;
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
							 case 1:doc1->AddSong();
								 break;
							 case 2:doc1->createNewPlaylist();
								 break;
							 case 3:
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
							 cout << "\n" << "Enter option:" << endl;
							 cout << "1. display songs" << endl;
							 cout << "2. display artists " << endl;
							 cout << "3. display albums" << endl;
							 cout << "4. display playlists " << endl;
							 cout << "5. display single song" << endl;
							 cout << "6. display single artist " << endl;
							 cout << "7. display single album" << endl;
							 cout << "8. display particular playlist " << endl;
							 cout << "9.exit" << endl;
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
								 doc->display_singlesong();
								 break;
							 case 6:
								 doc->display_singleartist();
								 break;
							 case 7:
								 doc->display_singlealbum();
								 break;
							 case 8:
								 doc->display_particularplaylist();
								 break;
							 case 9:
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
		 }
		 break;
		 case 2:
		 {
			 do
			 {
				 cout << "\n" << "Enter option:" << endl;
				 cout << "1. insert " << endl;
				 cout << "2. display " << endl;
				 cout << "3. Delete  " << endl;
				 cout << "4. Update  " << endl;
				 cout << "5. exit" << endl;
				 cin >> option3;
				 switch (option3)
				 {
				 case 1:
				 {
					 while (new_value1)				//using while loop
					 {
						 cout << "\n" << "Enter option:" << endl;
						 cout << "1. insert song" << endl;
						 cout << "2. Add playlist " << endl;
						 cout << "3.exit" << endl;
						 cin >> option4;
						 if (cin.fail())
						 {
							 cin.clear();
							 cin.ignore(numeric_limits<streamsize>::max(), '\n');
							 cout << "Enter valid type " << '\t';
							 continue;
						 }
						 switch (option4)
						 {
						 case 1:data.insert_song();
							 break;
						 case 2:data.createplaylist();
							 break;
						 case 3:
							 new_value1 = 0;
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
					 while (new_value2)				//using while loop
					 {
					 cout << "\n" << "Enter option:" << endl;
					 cout << "1. display song" << endl;
					 cout << "2. display artist " << endl;
					 cout << "3. display album " << endl;
					 cout << "4. display playlist " << endl;
					 cout << "5. display single song" << endl;
					 cout << "6. display single artist " << endl;
					 cout << "7. display single album" << endl;
					 cout << "8. display particular playlist " << endl;
					 cout << "9.exit" << endl;
					 cin >> option5;
					 if (cin.fail())
					 {
						 cin.clear();
						 cin.ignore(numeric_limits<streamsize>::max(), '\n');
						 cout << "Enter valid type " << '\t';
						 continue;
					 }
					 switch (option5)
					 {
					 case 1:data.displaySongs();
						 break;
					 case 2:data.displayArtists();
						 break;
					 case 3:data.displayAlbums();
					 case 4:data.displayPlaylist();
					 case 5:data.display_singlesong();
					 case 6:data.display_singleartist();
					 case 7:data.display_singlealbum();
					 case 8:data.display_singleplaylist();
					 case 9:
						 new_value2 = 0;
						 break;
					 default:
						 cout << "Enter valid option " << endl;
						 break;
					 }
					}
				 
				 break;
			 }
				 case 3:
					 data.delete_song();
					 break;
			 case 4:
			 {
				 while (new_value3)				//using while loop
				 {
					 cout << "\n" << "Enter option:" << endl;
					 cout << "1. update song" << endl;
					 cout << "2. update artist " << endl;
					 cout << "3. update album " << endl;
					 cout << "4. update playlist " << endl;
					 cout << "5.exit" << endl;
					 cin >> option6;
					 if (cin.fail())
					 {
						 cin.clear();
						 cin.ignore(numeric_limits<streamsize>::max(), '\n');
						 cout << "Enter valid type " << '\t';
						 continue;
					 }
					 switch (option6)
					 {
					 case 1:data.update_song();
						 break;
					 case 2:data.update_artist();
						 break;
					 case 3:data.update_album();
					 case 4:data.update_playlist();

					 case 5:
						 new_value3 = 0;
						 break;
					 default:
						 cout << "Enter valid option " << endl;
						 break;
					 }
				 }
			 }
			 break;
			 case 5:
				 new_value4 = 0;
				 break;
			 default:
				 cout << "Enter valid option " << endl;
				 break;
			 }
		} while (new_value4);

	}
	break;
	case 3:
			value3 = 0;
			break;
	default:
		cout << "Enter valid option " << endl;
		break;
		 }
  } while (value3);


		 cin.get();
		 cin.ignore(1000, '\n');
		 return 0;
}




































