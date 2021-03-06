#include "SyntaxTree.h"
#include "parse.h"

Node *tree;
int errorLexFlag;
int errorSyntaxFlag;

int main(int argc, char** argv){
	if(argc <= 1)
			return 1;
	FILE *f = fopen(argv[1], "r");
	if(!f){
		perror(argv[1]);
		return 1;
	}


	tree = NULL;	
	errorLexFlag = 0;
	errorSyntaxFlag = 0;
	yylineno = 1;
	yyrestart(f);
	yyparse();
	
	if(errorLexFlag == 0 && errorSyntaxFlag==0)
		traverseTree(tree);
	
	cleanTree(tree);
	return 0;

}
