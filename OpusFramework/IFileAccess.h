#pragma once
#pragma warning(disable:4996)

enum class FileAccessType
{
	Read,
	Write,

	kCount
};

class IFileAccess
{
public:
	IFileAccess(LPCSTR, ...);
	~IFileAccess();

	bool FileOpen(FileAccessType);
	void FileClose();

	char *FileRead(size_t &);

	void FileWrite(char *, size_t);

	LPCSTR GetFilePath();

private:
	char s_filePath[MAX_PATH] = {};
	FILE *s_pFile = 0;

	char *s_pBuffer = 0;
	size_t s_size = 0;
};