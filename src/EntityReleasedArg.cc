static const char *id = " @(#) $Id: EntityReleasedArg.cc,v 1.1.2.3 2019/06/29 02:24:31 mrafi Exp $";

#include "EntityReleasedArg.h"

using namespace capphase3;

EntityReleasedArg::EntityReleasedArg()
{
	mcallSegmentFailure = NULL;
	mbCSM_Failure = NULL;
	mTagsPresent = 0;
	mParamSet = false;
	mTag = 0X0000;
	mTagArray = {0X00A0, 0X00A1};
}

EntityReleasedArg::~EntityReleasedArg()
{
	if(mcallSegmentFailure != NULL)
		delete mcallSegmentFailure;
	if(mbCSM_Failure != NULL)
		delete mbCSM_Failure;
}

CallSegmentFailure* EntityReleasedArg::setcallSegmentFailure(){
if(mParamSet == true)
	if(mcallSegmentFailure != NULL)
		return mcallSegmentFailure;
	else
		return NULL;
	if(mcallSegmentFailure == NULL)
	{
		mcallSegmentFailure = new CallSegmentFailure();
		mTagsPresent |= EntityReleasedArg_CALLSEGMENTFAILURE;
		mParamSet = true;
		return mcallSegmentFailure;
	}
}

bool EntityReleasedArg::setcallSegmentFailure(CallSegmentFailure* callSegmentFailure){
	if(mcallSegmentFailure == NULL)
	{
		return -1;
	}
	else
	{
		mcallSegmentFailure = callSegmentFailure;
		return true;
	}

}

BCSM_Failure* EntityReleasedArg::setbCSM_Failure(){
if(mParamSet == true)
	if(mbCSM_Failure != NULL)
		return mbCSM_Failure;
	else
		return NULL;
	if(mbCSM_Failure == NULL)
	{
		mbCSM_Failure = new BCSM_Failure();
		mTagsPresent |= EntityReleasedArg_BCSM_FAILURE;
		mParamSet = true;
		return mbCSM_Failure;
	}
}

bool EntityReleasedArg::setbCSM_Failure(BCSM_Failure* bCSM_Failure){
	if(mbCSM_Failure == NULL)
	{
		return -1;
	}
	else
	{
		mbCSM_Failure = bCSM_Failure;
		return true;
	}

}

CallSegmentFailure* EntityReleasedArg::getcallSegmentFailure()  { // //{//throw(const char*)
	if(NULL == mcallSegmentFailure)
		throw("Object callSegmentFailure is NULL");
	else
		return mcallSegmentFailure;
}

BCSM_Failure* EntityReleasedArg::getbCSM_Failure()  { // //{//throw(const char*)
	if(NULL == mbCSM_Failure)
		throw("Object bCSM_Failure is NULL");
	else
		return mbCSM_Failure;
}

bool EntityReleasedArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int EntityReleasedArg::Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0, lengthSize = 0;
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
			case 0X00A0:
				if(NULL == this->setcallSegmentFailure())
					return -1;
				if(mcallSegmentFailure->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			case 0X00A1:
				if(NULL == this->setbCSM_Failure())
					return -1;
				if(mbCSM_Failure->Decode(array, &bytesDecoded) < 0)
					decode = false;
				lParamSet = true;
				break;
			default:
				printf("Unknown Tag received in Datatype: EntityReleasedArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("EntityReleasedArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int EntityReleasedArg::Encode(capstd::capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("EntityReleasedArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case EntityReleasedArg_CALLSEGMENTFAILURE:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcallSegmentFailure->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				mParamSet = false;
				break;
			case EntityReleasedArg_BCSM_FAILURE:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mbCSM_Failure->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
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

int EntityReleasedArg::Display(int tab){
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
			case EntityReleasedArg_CALLSEGMENTFAILURE:
			{
				printf(temp, " ", "callSegmentFailure");
				if(mcallSegmentFailure->Display(tab+1) < 0)
					return -1;
				break;
			}
			case EntityReleasedArg_BCSM_FAILURE:
			{
				printf(temp, " ", "bCSM_Failure");
				if(mbCSM_Failure->Display(tab+1) < 0)
					return -1;
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

bool EntityReleasedArg::ValidateMandatory(char *errStr){

	return true;
}
