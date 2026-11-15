static const char *id = " @(#) $Id: SplitLegArg.cc,v 1.1.2.3 2019/06/29 02:24:32 mrafi Exp $";

#include "SplitLegArg.h"

using namespace capphase3;

SplitLegArg::SplitLegArg()
{
	mlegToBeSplit = NULL;
	mnewCallSegment = NULL;
	mextensions = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X0081, 0X00A2};
	mTagOptional = {false, true, true};
}

SplitLegArg::~SplitLegArg()
{
	if(mlegToBeSplit != NULL)
		delete mlegToBeSplit;
	if(mnewCallSegment != NULL)
		delete mnewCallSegment;
	if(mextensions != NULL)
		delete mextensions;
}

LegID* SplitLegArg::setlegToBeSplit(){
	if(mlegToBeSplit == NULL)
	{
		mlegToBeSplit = new LegID();
		mTagsPresent |= SplitLegArg_LEGTOBESPLIT;
		return mlegToBeSplit;
	}
	else
		return mlegToBeSplit;

}

bool SplitLegArg::setlegToBeSplit(LegID* legToBeSplit){
	if(mlegToBeSplit == NULL)
	{
		return -1;
	}
	else
	{
		mlegToBeSplit = legToBeSplit;
		return true;
	}

}

capstd::capstd::INTEGER* SplitLegArg::setnewCallSegment(){
	if(mnewCallSegment == NULL)
	{
		mnewCallSegment = new capstd::INTEGER(1, 127);
		mTagsPresent |= SplitLegArg_NEWCALLSEGMENT;
		return mnewCallSegment;
	}
	else
		return mnewCallSegment;

}

bool SplitLegArg::setnewCallSegment(capstd::capstd::INTEGER* newCallSegment){
	if(mnewCallSegment == NULL)
	{
		return -1;
	}
	else
	{
		mnewCallSegment = newCallSegment;
		return true;
	}

}

Extensions* SplitLegArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= SplitLegArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool SplitLegArg::setextensions(Extensions* extensions){
	if(mextensions == NULL)
	{
		return -1;
	}
	else
	{
		mextensions = extensions;
		return true;
	}

}

LegID* SplitLegArg::getlegToBeSplit()  { // //{//throw(const char*)
	if(NULL == mlegToBeSplit)
		throw("Object legToBeSplit is NULL");
	else
		return mlegToBeSplit;
}

capstd::capstd::INTEGER* SplitLegArg::getnewCallSegment()  { // //{//throw(const char*)
	if(NULL == mnewCallSegment)
		throw("Object newCallSegment is NULL");
	else
		return mnewCallSegment;
}

Extensions* SplitLegArg::getextensions()  { // //{//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

bool SplitLegArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int SplitLegArg::Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0, lengthSize = 0;
	unsigned bytesDecoded = 0;

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
	while(length && decode)
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
				if(NULL == this->setlegToBeSplit())
					return -1;
				if(mlegToBeSplit->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setnewCallSegment())
					return -1;
				if(mnewCallSegment->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A2:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: SplitLegArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("SplitLegArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int SplitLegArg::Encode(capstd::capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("SplitLegArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
		return -1;
	}

	if(asn1_tag_encode(mTag, array) < 0)
		return -1;

	lLengthOffset = array->offset++;
	lTemp = ffs((int)tagsPresent);
	lSwitchTemp = (1U << (lTemp - 1));

	while(lTemp)
	{
		unsigned lengthOffset = 0;
		switch(lSwitchTemp)
		{
			case SplitLegArg_LEGTOBESPLIT:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlegToBeSplit->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SplitLegArg_NEWCALLSEGMENT:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mnewCallSegment->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case SplitLegArg_EXTENSIONS:
				if(asn1_tag_encode(162, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mextensions->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
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

int SplitLegArg::Display(int tab){
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
			case SplitLegArg_LEGTOBESPLIT:
			{
				printf(temp, " ", "legToBeSplit");
				if(mlegToBeSplit->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SplitLegArg_NEWCALLSEGMENT:
			{
				printf(temp, " ", "newCallSegment");
				if(mnewCallSegment->Display(tab+1) < 0)
					return -1;
				break;
			}
			case SplitLegArg_EXTENSIONS:
			{
				printf(temp, " ", "extensions");
				if(mextensions->Display(tab+1) < 0)
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

bool SplitLegArg::ValidateMandatory(char *errStr){
	if(NULL == mlegToBeSplit)
	{
		strcpy(errStr, "legToBeSplit");
		return false;
	}

	return true;
}
