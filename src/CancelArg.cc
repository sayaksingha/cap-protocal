#include "CancelArg.h"

using namespace capphase3;

CancelArg::CancelArg()
{
	minvokeID = NULL;
	mallRequests = false;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X0080, 0X0081};
}

CancelArg::~CancelArg()
{
	if(minvokeID != NULL)
		delete minvokeID;
}

capstd::INTEGER* CancelArg::setinvokeID(){
if(mParamSet == true)
	{
		if(minvokeID != NULL)
			return minvokeID;
		else
			return NULL;
	}
	if(minvokeID == NULL)
	{
		minvokeID = new capstd::INTEGER(0, 127);
		mTagsPresent |= CancelArg_INVOKEID;
		mParamSet = true;
		return minvokeID;
	}
}

bool CancelArg::setinvokeID(capstd::INTEGER* invokeID){
	if(minvokeID == NULL)
	{
		return -1;
	}
	else
	{
		minvokeID = invokeID;
		return true;
	}

}

bool* CancelArg::setallRequests(){
if(mParamSet == true)
	{
		if(mNullallRequests == true)
			return &mallRequests;
		else
			return NULL;
	}
	mTagsPresent |= CancelArg_ALLREQUESTS;
		mParamSet = true;
	mNullallRequests = true;
	return &mNullallRequests;
}

bool CancelArg::setallRequests(bool allRequests){
	mallRequests = allRequests;
	return true;
}

capstd::INTEGER* CancelArg::getinvokeID() {//throw(const char*)
	if(NULL == minvokeID)
		throw("Object invokeID is NULL");
	else
		return minvokeID;
}

bool CancelArg::getallRequests() {
	return mallRequests;
}

bool CancelArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CancelArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
	unsigned bytesDecoded = 0;

	bool lParamSet = false;
	unsigned tag = 0;
	asn1_tag_get(array, &tag);
	(*bytesParsed) = 0;

	//This is for the sequence of choice datatype with no tag given to choice datatype
	if(lengthDecode)
	{
		lengthSize = asn1_length_decode(array, &definite, &length);

		if(-1 == lengthSize)
			return -1;
		if(!definite)
		{
			length = 1;
		}
	}
	else
		length = 1;
	while(length && decode && !lParamSet)
	{
		bytesDecoded = 0;
		unsigned tag = 0;
		char  tagSize = 0;
		tagSize = asn1_tag_get(array, &tag);
		if(tagSize == -1)
			return -1;

		switch(tag)
		{
			case 0X0080:
				if(NULL == this->setinvokeID())
					return -1;
				if(minvokeID->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X0081:
				if(NULL == this->setallRequests())
					return -1;
				if(asn1_null_decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: CancelArg Tag:%d Offset:%d\n", tag, array->offset);
				if(asn1_skip_unknown(array, &bytesDecoded) < 0)
					return -1;
		}
		if(!definite)
		{
			if((array->byte[array->offset] == 0x00 && array->byte[array->offset + 1] == 0x00) || !decode)
			{
				length += bytesDecoded + tagSize;
				array->offset += 2;
				(*bytesParsed) += length - 1 + 2;
				break;
			}
			if(array->size < array->offset)
			{
				length += bytesDecoded + tagSize;
				(*bytesParsed) += length - 1 + 2;
				printf("not found eoc size %d offset %d", array->size, array->offset);
				return -1;
			}
			(*bytesParsed) += bytesDecoded + tagSize;
		}
		else
		{
			(*bytesParsed) += bytesDecoded + tagSize;
			length -= bytesDecoded + tagSize;
			if(length < 0 || (array->size < array->offset))
				return -1;
		}
	}
	(*bytesParsed) += lengthSize;
	if(!decode)
		return -1;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CancelArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CancelArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CancelArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	if(asn1_tag_encode(mTag, array) < 0)
		return -1;

	lLengthOffset = array->offset++;
	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp && mParamSet)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case CancelArg_INVOKEID:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((minvokeID->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case CancelArg_ALLREQUESTS:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				asn1_null_encode(array);
				mParamSet = false;
				break;
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
				//return -1;
				break;
		}
		tagsPresent = tagsPresent & ~(lSwitchTemp);
		lTemp = ffs((int)tagsPresent);
		lSwitchTemp = (1U << (lTemp - 1));
	}
	if(asn1_length_encode(lLengthOffset, array, &lIndefinite) < 0)
		return -1;

	return 0;
}

int CancelArg::Display(int tab){
	unsigned lTemp = 0;
	char temp[30];
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;

	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));
	sprintf(temp, "%%%ds %%s\n", tab * 3);

	while(lTemp)
	{
		switch(lSwitchTemp)
		{
			case CancelArg_INVOKEID:
			{
				printf(temp, " ", "invokeID");
				if(minvokeID->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CancelArg_ALLREQUESTS:
			{
				printf(temp, " ", "allRequests");
				break;
			}
			default:
				//printf("Unknown Tag received Tag:%d Offset:%d\n", mTagArray[lTemp], array->offset);
				//return -1;
				break;
		}
		tagsPresent = tagsPresent & ~(lSwitchTemp);
		lTemp = ffs((int)tagsPresent);
		lSwitchTemp = (1U << (lTemp - 1));
	}
	return 1;
}

bool CancelArg::ValidateMandatory(char *errStr){

	return true;
}
