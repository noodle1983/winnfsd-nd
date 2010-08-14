#ifndef _MOUNTPROG_H_
#define _MOUNTPROG_H_

#include "RPCProg.h"
#include <map>
#include <string>
using namespace std;

#define MOUNT_NUM_MAX 100

class CMountProg : public CRPCProg
{
public:
	CMountProg();
	virtual ~CMountProg();
	void Export(const string& winPath, const string& exportName);
	char *GetClientAddr(int nIndex);
	int GetMountNumber(void);
	int Process(IInputStream *pInStream, IOutputStream *pOutStream, ProcessParam *pParam);

	void trimBy(char* str, int len, char c);

protected:
	int m_nMountNum;
	//char m_pExportPath[MAXPATHLEN];
	char *m_pClientAddr[MOUNT_NUM_MAX];
	IInputStream *m_pInStream;
	IOutputStream *m_pOutStream;

	void ProcedureNULL(void);
	void ProcedureMNT(void);
	void ProcedureUMNT(void);
	void ProcedureNOIMP(void);

private:
	map<string, string> m_pathsOfname;
	ProcessParam *m_pParam;
	int m_nResult;

	char *GetPath(void);
};

#endif
