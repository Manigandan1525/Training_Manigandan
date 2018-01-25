#include "sql_database.h"



sql_database::sql_database()
{
	SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle);

	SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

	SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle);

	SQLDriverConnect(sqlConnHandle,
		NULL,
		(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=IN11W-TRAINEE-2\\SQLEXPRESS, 49293;DATABASE=Music;UID=sa;PWD=abc123$%^;",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT);
}


sql_database::~sql_database()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
}

void sql_database::displaySongs()
{
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select song_name,length,artist_name,album_name from songs join artist on songs.artist_id = artist.artist_id join album on songs.album_id = album.album_id", SQL_NTS);
	cout << "Song Details:" << '\n' << endl;
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;
		SQLGetData(sqlStmtHandle, 3, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;
		SQLGetData(sqlStmtHandle, 4, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << '\n' << endl;

	}
	cout << '\n';
}
void sql_database::displayArtists()
{
	char string[50];
	char string1[50];
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select artist_name,song_name from artist join artist_Ref on artist.artist_id = artist_Ref.artist_id join songs on songs.Id = artist_Ref.artistsong_id", SQL_NTS);
	cout << "Song Details:" << '\n' << endl;
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		strcpy_s(string, (char*)sqlVersion);
		if (strcmp(string1, (char*)sqlVersion) != 0)
		{
			cout << sqlVersion << endl;
		}
		strcpy_s(string1, string);
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;

	}
	cout << '\n';
}
void sql_database::displayAlbums()
{
	char string[50];
	char string1[50];
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select album_name,song_name from album join album_Ref on album.album_id = album_Ref.album_id join songs on songs.Id = album_Ref.albumsong_id", SQL_NTS);
	cout << "Song Details:" << endl;
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		strcpy_s(string, (char*)sqlVersion);
		if (strcmp(string1, (char*)sqlVersion) != 0)
		{
			cout << sqlVersion << endl;
		}
		strcpy_s(string1, string);
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;
	}
	cout << '\n';
}
void sql_database::displayPlaylist()
{
	char string[50];
	char string1[50];
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select playlistname,song_name from playlist join playlist_Ref on playlist.playlist_id = playlist_Ref.playlist_id join songs on songs.Id = playlist_Ref.playlistsong_id", SQL_NTS);
	cout << "Song Details:" << endl;
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		strcpy_s(string, (char*)sqlVersion);
		if (strcmp(string1, (char*)sqlVersion) != 0)
		{
			cout << sqlVersion << endl;
		}
		strcpy_s(string1, string);
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;
	}
}
void sql_database::display_singlesong()
{
	char   PartID[20], asd[20];
	SQLINTEGER    PartIDInd = SQL_NTS;
	cin >> asd;
 
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"select song_name,length,artist_name,album_name from songs join artist on songs.artist_id = artist.artist_id join album on songs.album_id = album.album_id WHERE song_name =?", SQL_NTS);

	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 10, 0, &PartID, 0, &PartIDInd);
	strcpy_s(PartID, asd);

	SQLExecute(sqlStmtHandle);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;
		SQLGetData(sqlStmtHandle, 3, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;
		SQLGetData(sqlStmtHandle, 4, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;
	}
}

void sql_database::display_singleartist()
{
	char string[50];
	char string1[50];
	char   PartID[20], asd[20];
	SQLINTEGER    PartIDInd = SQL_NTS;
	cin >> asd;
	 
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"select artist_name,song_name from artist join artist_Ref on artist.artist_id = artist_Ref.artist_id join songs on songs.Id = artist_Ref.artistsong_id WHERE artist_name =? ", SQL_NTS);

	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 10, 0, &PartID, 0, &PartIDInd);
	strcpy_s(PartID, asd);

	SQLExecute(sqlStmtHandle);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		strcpy_s(string, (char*)sqlVersion);
		if (strcmp(string1, (char*)sqlVersion) != 0)
		{
			cout << sqlVersion << endl;
		}
		strcpy_s(string1, string);
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;

	}
}

void sql_database::display_singlealbum()
{
	char string[50], album[50];
	char string1[50], compilation_album[50];
	char   PartID[20], asd[20];
	SQLINTEGER    PartIDInd = SQL_NTS;
	cin >> asd;
 
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"select album_name,compilation_album,song_name from album join album_Ref on album.album_id = album_Ref.album_id join songs on songs.Id = album_Ref.albumsong_id WHERE album_name =? ", SQL_NTS);

	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 10, 0, &PartID, 0, &PartIDInd);
	strcpy_s(PartID, asd);

	SQLExecute(sqlStmtHandle);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		strcpy_s(string, (char*)sqlVersion);
		if (strcmp(string1, (char*)sqlVersion) != 0)
		{
			cout << '\t' << sqlVersion << endl;
		}
		strcpy_s(string1, string);
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		strcpy_s(album, (char*)sqlVersion);
		if (strcmp(compilation_album, (char*)sqlVersion) != 0)
		{
			cout << '\t' << sqlVersion << endl;
		}
		strcpy_s(compilation_album, album);
		SQLGetData(sqlStmtHandle, 3, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;
	}
}

void sql_database::display_singleplaylist()
{
	char string[50];
	char string1[50];
	char   PartID[20], asd[20];
	SQLINTEGER    PartIDInd = SQL_NTS;
	cin >> asd;

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"select playlistname,song_name from playlist join playlist_Ref on playlist.playlist_id = playlist_Ref.playlist_id join songs on songs.Id = playlist_Ref.playlistsong_id WHERE playlistname =? ", SQL_NTS);

	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 10, 0, &PartID, 0, &PartIDInd);
	strcpy_s(PartID, asd);

	SQLExecute(sqlStmtHandle);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		strcpy_s(string, (char*)sqlVersion);
		if (strcmp(string1, (char*)sqlVersion) != 0)
		{
			cout << sqlVersion << endl;
		}
		strcpy_s(string1, string);
		SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;
	}
}

void sql_database::insert_song()
{
	int count = 0, artist_count = 0, album_count = 0;
	char   PartID[20], asd[20];
	char   PartID2[20], asd2[20];
	char   PartID3[20], asd3[20];
	char   PartID4[20], asd4[20];
	char   PartID5[20], asd5[20];
	SQLINTEGER    PartIDInd = SQL_NTS;
	cin >> asd2;
	cin >> asd3;
	cin >> asd4;
	cin >> asd5;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select Id from songs", SQL_NTS);
	cout << "Song Details:" << endl;

	SQLExecute(sqlStmtHandle);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		count++;
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);

		if (strcmp(asd2, (char*)sqlVersion) == 0)
		{
			cout << "you entered song is already exists.." << endl;
			return;
		}
	}
	cout << count << endl;
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, L"INSERT INTO songs(Id,song_name,length) VALUES (?,?,?)", SQL_NTS);

	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID2, 0, &PartIDInd);
	SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID3, 0, &PartIDInd);
	string a = "s" + to_string(count + 1);
	strcpy_s(PartID, a.c_str());
	strcpy_s(PartID2, asd2);
	strcpy_s(PartID3, asd3);

	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "";
	}

	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select artist_name from artist", SQL_NTS);
	count = 0;
	SQLExecute(sqlStmtHandle);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		artist_count++;
		count++;
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << sqlVersion << endl;
		if (strcmp(asd4, (char*)sqlVersion) == 0)
		{
			SQLINTEGER    PartIDInd = SQL_NTS;
			SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
			SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
			SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update songs set artist_id =? WHERE Id =? ", SQL_NTS);

			SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, PartID, 0, &PartIDInd);
			SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, PartID2, 0, &PartIDInd);

			string s = "art" + to_string(count);
			strcpy_s(PartID, s.c_str());
			strcpy_s(PartID2, a.c_str());
			cout << "you entered artist is already exists.." << endl;
			if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
			{
				cout << "";
			}

			insertdata_inArtist(artist_count, a);

			artist_count--;
			SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
		}
	}
	if (artist_count == count)
	{
		count++;		SQLINTEGER    PartIDInd = SQL_NTS;
		SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update songs set artist_id =? WHERE Id =? ", SQL_NTS);

		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, PartID, 0, &PartIDInd);
		SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, PartID2, 0, &PartIDInd);

		string s = "art" + to_string(count);
		strcpy_s(PartID, s.c_str());
		strcpy_s(PartID2, a.c_str());
		if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
		{
			cout << "";
		}
		insert_artist(count, asd4);
		insertdata_inArtist(count, a);
		cout << artist_count << endl;
		cout << "create new artist" << endl;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select album_name from album", SQL_NTS);
	count = 0;
	SQLExecute(sqlStmtHandle);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		album_count++;
		count++;
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << sqlVersion << endl;
		if (strcmp(asd5, (char*)sqlVersion) == 0)
		{
			SQLINTEGER    PartIDInd = SQL_NTS;
			SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
			SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
			SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update songs set album_id =? WHERE Id =? ", SQL_NTS);
			SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, PartID, 0, &PartIDInd);
			SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, PartID2, 0, &PartIDInd);
			string s = "alb" + to_string(count);
			strcpy_s(PartID, s.c_str());
			strcpy_s(PartID2, a.c_str());
			cout << "you entered album is already exists.." << endl;
			if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
			{
				cout << "";
			}
			insertdata_inAlbum(album_count, a);
			album_count--;
			SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
		}
	}
	if (album_count == count)
	{
		count++;		SQLINTEGER    PartIDInd = SQL_NTS;
		SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
		SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
		SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update songs set album_id =? WHERE Id =? ", SQL_NTS);
		SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, PartID, 0, &PartIDInd);
		SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, PartID2, 0, &PartIDInd);
		string s = "alb" + to_string(count);
		strcpy_s(PartID, s.c_str());
		strcpy_s(PartID2, a.c_str());
		if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
		{
			cout << "";
		}
		insert_album(count, asd5);
		insertdata_inAlbum(count, a);
		cout << album_count << endl;
		cout << "create new album" << endl;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	cout << "song inserted successfully!!" << endl;
}

void sql_database::insert_artist(int count, char* asd4)
{

	char   PartID[20], asd[20];
	char   PartID2[20], asd2[20];

	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLINTEGER    PartIDInd = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"INSERT INTO artist(artist_Id,artist_name) VALUES (?,?) select * from artist_Ref order by artist_id", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID2, 0, &PartIDInd);
	string a = "art" + to_string(count);
	strcpy_s(PartID, a.c_str());
	strcpy_s(PartID2, asd4);

	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "****************";
	}
}

void sql_database::insert_album(int count, char* asd5)
{
	char   PartID[20], asd[20];
	char   PartID2[20], asd2[20];
	char   PartID3[20], asd3[20];
	char com[20] = "true", com1[20] = "false";
	char compilation;
	while (1)
	{
		cout << "The album is compilation album(y/n)" << endl;
		cin >> compilation;
		if (compilation == 'y')
		{
			strcpy_s(asd3, com);
			break;
		}
		else if (compilation == 'n')
		{
			strcpy_s(asd3, com1);
			break;
		}
		else
		{
			cout << "Enter correct option" << endl;
		}
	}
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLINTEGER    PartIDInd = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"INSERT INTO album(album_id,compilation_album,artist_name) VALUES (?,?,?) select * from artist_Ref order by artist_id", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID2, 0, &PartIDInd);
	SQLBindParameter(sqlStmtHandle, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID3, 0, &PartIDInd);
	string a = "alb" + to_string(count);
	strcpy_s(PartID, a.c_str());
	strcpy_s(PartID2, asd3);
	strcpy_s(PartID2, asd5);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "****************";
	}
}

void sql_database::insertdata_inArtist(int count, string s)
{


	char   PartID[20], asd[20];
	char   PartID2[20], asd2[20];
	char   PartID3[20], asd3[20];
	char   PartID4[20], asd4[20];
	char   PartID5[20], asd5[20];
	SQLINTEGER    PartIDInd = SQL_NTS;
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"INSERT INTO artist_Ref(artist_id,artistsong_id) VALUES (?,?)", SQL_NTS);

	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID2, 0, &PartIDInd);
	string a = "art" + to_string(count);
	strcpy_s(PartID, a.c_str());
	strcpy_s(PartID2, s.c_str());

	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "********";
	}

}

void sql_database::insertdata_inAlbum(int count, string s)
{
	char   PartID[20], asd[20];
	char   PartID2[20], asd2[20];
	char   PartID3[20], asd3[20];
	char   PartID4[20], asd4[20];
	char   PartID5[20], asd5[20];
	SQLINTEGER    PartIDInd = SQL_NTS;
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"INSERT INTO album_Ref(album_id,albumsong_id) VALUES (?,?)", SQL_NTS);

	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID2, 0, &PartIDInd);
	string a = "alb" + to_string(count);
	strcpy_s(PartID, a.c_str());
	strcpy_s(PartID2, s.c_str());

	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "********";
	}
}

void sql_database::createplaylist()
{
	char   PartID[20], asd[20];
	char   PartID2[20], asd2[20];
	cout << "Enter playlist name" << endl;
	cin >> asd;
	int count = 0;
	int playlist_count = 0;
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select playlist_name from playlist", SQL_NTS);
	count = 0;
	SQLExecute(sqlStmtHandle);
	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS)
	{
		playlist_count++;
		count++;
		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << sqlVersion << endl;
	}
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLINTEGER    PartIDInd = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"INSERT INTO playlist(playlist_id,playlist_name) VALUES (?,?)", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID2, 0, &PartIDInd);
	string a = "list" + to_string(count + 1);
	strcpy_s(PartID, a.c_str());
	strcpy_s(PartID2, asd);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "********";
	}
	insertsong_inPlaylist(a);
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
}
void sql_database::insertsong_inPlaylist(string a)
{
	char   PartID[20], asd[20];
	char PartID2[20], asd1[20];
	char character;
	int count = 0;


	while (1)
	{
		cout << "If you insert song in playlist(y/n)" << endl;
		cin >> character;
		if (character == 'y')
		{
			cout << "Enter song name";
			cin >> asd;
			SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
			SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select song_name,Id from songs", SQL_NTS);

			while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

				SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
				cout << '\t' << sqlVersion << endl;
				if (strcmp(asd, (char*)sqlVersion) == 0)
				{
					count = 1;
					SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
					cout << '\t' << sqlVersion << endl;
					strcpy_s(asd1, (char*)sqlVersion);
				}
			}
			if (count == 0)
			{
				cout << "You entered wrong song";
			}
			else
			{
				SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
				SQLINTEGER    PartIDInd = SQL_NTS;
				SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
				SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"INSERT INTO playlist_Ref(playlist_id,playlistsong_id) VALUES (?,?)", SQL_NTS);
				SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
				SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID2, 0, &PartIDInd);
				strcpy_s(PartID, a.c_str());
				strcpy_s(PartID2, asd1);
				if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
				{
					cout << "********";
				}
			}
		}
		else if (character == 'n')
		{
			break;
		}
		else
		{
			cout << "Enter correct option" << endl;
		}
		cin >> asd;
	}

}

void sql_database::delete_song()
{
	char   PartID[20], asd[20];
	char   PartID2[20], asd1[20];
	int count = 0;
	cout << "Enter song name" << endl;
	cin >> asd;
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"select song_name,Id from songs", SQL_NTS);

	while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {

		SQLGetData(sqlStmtHandle, 1, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
		cout << '\t' << sqlVersion << endl;
		if (strcmp(asd, (char*)sqlVersion) == 0)
		{
			count = 1;
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, sqlVersion, SQL_RESULT_LEN, &ptrSqlVersion);
			//cout << '\t' << sqlVersion << endl;
			strcpy_s(asd1, (char*)sqlVersion);
		}
	}
	if (count == 0)
	{
		cout << "You entered song name is wrong" << endl;
		return;
	}


	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLINTEGER    PartIDInd = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"delete from songs where song_name=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	strcpy_s(PartID, asd);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "";
	}

	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"delete from artist_Ref where artistsong_id=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	strcpy_s(PartID, asd1);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "";
	}

	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"delete from album_Ref where albumsong_id=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	strcpy_s(PartID, asd1);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "";
	}

	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);

	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"delete from playlist_Ref where playlistsong_id=?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	strcpy_s(PartID, asd1);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "Song deleted successfully!!" << endl;
	}
}


void sql_database::update_song()
{
	char   PartID[20], asd[20];
	char   PartID2[20], asd1[20];
	int count = 0;
	cout << "Enter song name" << endl;
	cin >> asd;
	cout << "Enter new song name to update" << endl;
	cin >> asd1;
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLINTEGER    PartIDInd = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update songs set song_name=? WHERE song_name =?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID2, 0, &PartIDInd);
	strcpy_s(PartID, asd1);
	strcpy_s(PartID2, asd);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "song update successfully!!" << endl;
	}
}
void sql_database::update_artist()
{
	char   PartID[20], asd[20];
	char   PartID2[20], asd1[20];
	int count = 0;
	cout << "Enter artist name" << endl;
	cin >> asd;
	cout << "Enter new artist name to update" << endl;
	cin >> asd1;
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLINTEGER    PartIDInd = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update artist set artist_name=? WHERE artist_name =?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID2, 0, &PartIDInd);
	strcpy_s(PartID, asd1);
	strcpy_s(PartID2, asd);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "artist update successfully!!" << endl;

	}
}
void sql_database::update_album()
{
	char   PartID[20], asd[20];
	char   PartID2[20], asd1[20];
	int count = 0;
	cout << "Enter album name" << endl;
	cin >> asd;
	cout << "Enter new album name to update" << endl;
	cin >> asd1;
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLINTEGER    PartIDInd = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update album set album_name=? WHERE album_name =?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID2, 0, &PartIDInd);
	strcpy_s(PartID, asd1);
	strcpy_s(PartID2, asd);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "album update successfully!!" << endl;

	}
}
void sql_database::update_playlist()
{
	char   PartID[20], asd[20];
	char   PartID2[20], asd1[20];
	int count = 0;
	cout << "Enter playlist name" << endl;
	cin >> asd;
	cout << "Enter new playlist name to update" << endl;
	cin >> asd1;
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLINTEGER    PartIDInd = SQL_NTS;
	SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle);
	SQLPrepare(sqlStmtHandle, (SQLWCHAR*)L"update playlist set playlist_name=? WHERE playlist_name =?", SQL_NTS);
	SQLBindParameter(sqlStmtHandle, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID, 0, &PartIDInd);
	SQLBindParameter(sqlStmtHandle, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, &PartID2, 0, &PartIDInd);
	strcpy_s(PartID, asd1);
	strcpy_s(PartID2, asd);
	if (SQLExecute(sqlStmtHandle) == SQL_SUCCESS)
	{
		cout << "playlist update successfully!!" << endl;

	}
}

