#ifndef FILTERS_H
#define FILTERS_H

#include "grpinfo.h"
#include <map>
#include <sstream>
using namespace std;

typedef map<uint8_t, string> I8strmap;
typedef map<uint8_t, pair<string, string> > I8strstrmap;
typedef unique_ptr<GrpInfo, GrpInfoDeleter> Giptr;
typedef map<uint32_t, Giptr> I32gimap;

inline void makemutinfo(int *arr, const string &ln, int m)
{
	stringstream ss(ln);
	string skip;
	ss >> skip;
	for(int i = 1; i < m; i++)
		ss >> arr[i];
}

inline void getselectcmd(string &cmd, const I8strstrmap &map, const int &id, size_t cnt)
{
	string lane = map.at(cnt).first;
	string mid = map.at(cnt).second;
	stringstream grpss;
	grpss << id;

	cmd.replace(53, 1, lane);
	cmd.replace(cmd.end()-18, cmd.end()-17, mid);
	cmd.replace(cmd.end()-2, cmd.end()-1, grpss.str());
}

inline pair<int, int> getidfr(const string &ln)
{
	stringstream ss(ln);
	int grpid, freq;
	ss >> grpid >> freq;
	return make_pair(grpid, freq);
}

#endif /* FILTERS_H */
