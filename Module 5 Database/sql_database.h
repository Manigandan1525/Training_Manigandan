#pragma once 
#define NOMINMAX
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string> 
#include <windows.h> 
#include <sqlext.h> 
#include <sqltypes.h> 
#include <sql.h> 

using namespace std;
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1000
class sql_database
{
private:
	SQLHANDLE sqlConnHandle = NULL;
	SQLHANDLE sqlStmtHandle = NULL;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
	SQLCHAR sqlVersion[SQL_RESULT_LEN];
	SQLINTEGER ptrSqlVersion;

public:
	sql_database();
	~sql_database();
	void displaySongs();
	void displayAlbums();
	void displayArtists();
	void displayPlaylist();
	void display_singlesong();
	void display_singleartist();
	void display_singlealbum();
	void display_singleplaylist();
	void insert_song();
	void insert_artist(int count, char* name);
	void insert_album(int count, char* name);
	void insertdata_inArtist(int count, string s);
	void insertdata_inAlbum(int count, string s);
	void createplaylist();
	void insertsong_inPlaylist(string value);
	void delete_song();
	void update_song();
	void update_artist();
	void update_album();
	void update_playlist();


};


