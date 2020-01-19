
#pragma warning( push )
#pragma warning( disable : 4146 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4267 )
#pragma warning( disable : 4291 )
#pragma warning( disable : 4624 )
#include <clang/Tooling/Tooling.h>
#pragma warning( pop )

#include <stdio.h>

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		printf("Incorrect number of arguments. Expected 3");
	}

	const char* szReflectionDirectory = argv[1];
	const char* szOutputHeader = argv[2];
	const char* szOutputSource = argv[3];

	printf("Reflection Directory: '%s'\n", szReflectionDirectory);
	printf("Reflection Output Header: '%s'\n", szOutputHeader);
	printf("Reflection Output Source: '%s'\n", szOutputSource);

	{
		FILE* pReflectionHeader = fopen(szOutputHeader, "w");
		assert(pReflectionHeader != nullptr);
		fflush(pReflectionHeader);
		fclose(pReflectionHeader);
	}

	{
		FILE* pReflectionSource = fopen(szOutputSource, "w");
		assert(pReflectionSource != nullptr);
		fflush(pReflectionSource);
		fclose(pReflectionSource);
	}

	return 0;
}


