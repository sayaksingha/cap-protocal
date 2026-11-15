static const char *id = " @(#) $Id: DisconnectLegArg.cc,v 1.1.2.3 2019/06/29 02:24:31 mrafi Exp $";

#include "DisconnectLegArg.h"

using namespace capphase3;

DisconnectLegArg::DisconnectLegArg()
{
	mlegToBeReleased = NULL;
	mreleaseCause = NULL;
	mextensions = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X0081, 0X00A2};
	mTagOptional = {false, true, true};
}

DisconnectLegArg::~DisconnectLegArg()
{
	if(mlegToBeReleased != NULL)
		delete mlegToBeReleased;
	if(mreleaseCause != NULL)
		delete mreleaseCause;
	if(mextensions != NULL)
		delete mextensions;
}

LegID* DisconnectLegArg::setlegToBeReleased(){
	if(mlegToBeReleased == NULL)
	{
		mlegToBeReleased = new LegID();
		mTagsPresent |= DisconnectLegArg_LEGTOBERELEASED;
		return mlegToBeReleased;
	}
	else
		return mlegToBeReleased;

}

bool DisconnectLegArg::setlegToBeReleased(LegID* legToBeReleased){
	if(mlegToBeReleased == NULL)
	{
		return -1;
	}
	else
	{
		mlegToBeReleased = legToBeReleased;
		return true;
	}

}

capstd::capstd::OctetString* DisconnectLegArg::setreleaseCause(){
	if(mreleaseCause == NULL)
	{
		mreleaseCause = new capstd::OctetString(2, 32);
		mTagsPresent |= DisconnectLegArg_RELEASECAUSE;
		return mreleaseCause;
	}
	else
		return mreleaseCause;

}

bool DisconnectLegArg::setreleaseCause(capstd::capstd::OctetString* releaseCause){
	if(mreleaseCause == NULL)
	{
		return -1;
	}
	else
	{
		mreleaseCause = releaseCause;
		return true;
	}

}

Extensions* DisconnectLegArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= DisconnectLegArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool DisconnectLegArg::setextensions(Extensions* extensions){
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

LegID* DisconnectLegArg::getlegToBeReleased()  { // //{//throw(const char*)
	if(NULL == mlegToBeReleased)
		throw("Object legToBeReleased is NULL");
	else
		return mlegToBeReleased;
}

capstd::capstd::OctetString* DisconnectLegArg::getreleaseCause()  { // //{//throw(const char*)
	if(NULL == mreleaseCause)
		throw("Object releaseCause is NULL");
	else
		return mreleaseCause;
}

Extensions* DisconnectLegArg::getextensions()  { // //{//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

bool DisconnectLegArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int DisconnectLegArg::Decode(capstd::capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
				if(NULL == this->setlegToBeReleased())
					return -1;
				if(mlegToBeReleased->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0081:
				if(NULL == this->setreleaseCause())
					return -1;
				if(mreleaseCause->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A2:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: DisconnectLegArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("DisconnectLegArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int DisconnectLegArg::Encode(capstd::capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("DisconnectLegArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case DisconnectLegArg_LEGTOBERELEASED:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mlegToBeReleased->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case DisconnectLegArg_RELEASECAUSE:
				if(asn1_tag_encode(129, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mreleaseCause->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case DisconnectLegArg_EXTENSIONS:
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

int DisconnectLegArg::Display(int tab){
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
			case DisconnectLegArg_LEGTOBERELEASED:
			{
				printf(temp, " ", "legToBeReleased");
				if(mlegToBeReleased->Display(tab+1) < 0)
					return -1;
				break;
			}
			case DisconnectLegArg_RELEASECAUSE:
			{
				printf(temp, " ", "releaseCause");
				if(mreleaseCause->Display(tab+1) < 0)
					return -1;
				break;
			}
			case DisconnectLegArg_EXTENSIONS:
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

bool DisconnectLegArg::ValidateMandatory(char *errStr){
	if(NULL == mlegToBeReleased)
	{
		strcpy(errStr, "legToBeReleased");
		return false;
	}

	return true;
}
