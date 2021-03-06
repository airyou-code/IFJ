/*------------------------------------------
 Title:  symtable.h
 Author: Golikov Ivan
 Login:  xgolik00 
 Date:   15 Oct 2021;
------------------------------------------*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "scanner.h"

#pragma once

typedef enum
{
    NO,
    sINT,
    sSTR,
    FLOAT,
    sNULL,
    sLOCAL,
    sGLOBAL
} typeVar;

typedef struct Parametrs
{
    char *name;
    typeVar type;
}parametr;

typedef struct return_val
{
    char *name;
    
}retVAl;

    typedef struct BSTNode
{
    char *name;            //name of function or variable
    char * data;           //value of variable(12, 2.2, "Hello")
    typeVar type[16];          //type of variable(int, double, str)
    typeVar scope;
    bool isFunction;       //node is function or variable
    struct Parametrs param[32];
    struct return_val retVal[16];
    struct BSTNode * LPtr; //left node
    struct BSTNode * RPtr; //right node
}
BSTNodePtr;

void smInit(BSTNodePtr **root);
/**
 * adde new func
* @param parametr_name if name is unknown use NULL
* @param parametr_type if name is unknown use NO
**/
int smInsertFunctin(BSTNodePtr **root, char *name, typeVar type, char *parametr_name, typeVar parametr_type, int param_num, int type_num);

int smAddRetVal(BSTNodePtr **root, char *retVal, int num_ret);

int smInsertVariable(BSTNodePtr **root, char *name, char *data, typeVar type, typeVar scope);

/**
 *searches by node name
 **/
BSTNodePtr *smSearchNode (BSTNodePtr *root, char *name);

/**
 * searches for a function that has a parameter 
 * @param name variable name
 **/
BSTNodePtr *smSearchParamNode(BSTNodePtr *root, char *name);

/**
 * returns a data type parameter parametr
 * searches for a parameter in the node
 **/
parametr *smSearcParamFunc(BSTNodePtr *root, char *name);

/**
 *searches only for variables in a function
 **/
BSTNodePtr *smChekVar(BSTNodePtr *root, char *name);

void smDispose (BSTNodePtr **root);

void smDeleteFunction (BSTNodePtr **root);
