#include "CallGapArg.h"

using namespace capphase3;

CallGapArg::CallGapArg()
{
	mgapCriteria = NULL;
	mgapIndicators = NULL;
	mcontrolType = NULL;
	mgapTreatment = NULL;
	mextensions = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X00A0, 0X00A1, 0X0082, 0X00A3, 0X00A4};
	mTagOptional = {false, false, true, true, true};
}

CallGapArg::~CallGapArg()
{
	if(mgapCriteria != NULL)
		delete mgapCriteria;
	if(mgapIndicators != NULL)
		delete mgapIndicators;
	if(mcontrolType != NULL)
		delete mcontrolType;
	if(mgapTreatment != NULL)
		delete mgapTreatment;
	if(mextensions != NULL)
		delete mextensions;
}

GapCriteria* CallGapArg::setgapCriteria(){
	if(mgapCriteria == NULL)
	{
		mgapCriteria = new GapCriteria();
		mTagsPresent |= CallGapArg_GAPCRITERIA;
		return mgapCriteria;
	}
	else
		return mgapCriteria;

}

bool CallGapArg::setgapCriteria(GapCriteria* gapCriteria){
	if(mgapCriteria == NULL)
	{
		return -1;
	}
	else
	{
		mgapCriteria = gapCriteria;
		return true;
	}

}

GapIndicators* CallGapArg::setgapIndicators(){
	if(mgapIndicators == NULL)
	{
		mgapIndicators = new GapIndicators();
		mTagsPresent |= CallGapArg_GAPINDICATORS;
		return mgapIndicators;
	}
	else
		return mgapIndicators;

}

bool CallGapArg::setgapIndicators(GapIndicators* gapIndicators){
	if(mgapIndicators == NULL)
	{
		return -1;
	}
	else
	{
		mgapIndicators = gapIndicators;
		return true;
	}

}

ControlType* CallGapArg::setcontrolType(){
	if(mcontrolType == NULL)
	{
		mcontrolType = new ControlType();
		mTagsPresent |= CallGapArg_CONTROLTYPE;
		return mcontrolType;
	}
	else
		return mcontrolType;

}

bool CallGapArg::setcontrolType(ControlType* controlType){
	if(mcontrolType == NULL)
	{
		return -1;
	}
	else
	{
		mcontrolType = controlType;
		return true;
	}

}

GapTreatment* CallGapArg::setgapTreatment(){
	if(mgapTreatment == NULL)
	{
		mgapTreatment = new GapTreatment();
		mTagsPresent |= CallGapArg_GAPTREATMENT;
		return mgapTreatment;
	}
	else
		return mgapTreatment;

}

bool CallGapArg::setgapTreatment(GapTreatment* gapTreatment){
	if(mgapTreatment == NULL)
	{
		return -1;
	}
	else
	{
		mgapTreatment = gapTreatment;
		return true;
	}

}

Extensions* CallGapArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= CallGapArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool CallGapArg::setextensions(Extensions* extensions){
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

GapCriteria* CallGapArg::getgapCriteria() {//throw(const char*)
	if(NULL == mgapCriteria)
		throw("Object gapCriteria is NULL");
	else
		return mgapCriteria;
}

GapIndicators* CallGapArg::getgapIndicators() {//throw(const char*)
	if(NULL == mgapIndicators)
		throw("Object gapIndicators is NULL");
	else
		return mgapIndicators;
}

ControlType* CallGapArg::getcontrolType() {//throw(const char*)
	if(NULL == mcontrolType)
		throw("Object controlType is NULL");
	else
		return mcontrolType;
}

GapTreatment* CallGapArg::getgapTreatment() {//throw(const char*)
	if(NULL == mgapTreatment)
		throw("Object gapTreatment is NULL");
	else
		return mgapTreatment;
}

Extensions* CallGapArg::getextensions() {//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

bool CallGapArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int CallGapArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
	bool    definite = true, decode = true;
	unsigned length = 0;

signed lengthSize = 0;
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
				if(NULL == this->setgapCriteria())
					return -1;
				if(mgapCriteria->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A1:
				if(NULL == this->setgapIndicators())
					return -1;
				if(mgapIndicators->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X0082:
				if(NULL == this->setcontrolType())
					return -1;
				if(mcontrolType->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A3:
				if(NULL == this->setgapTreatment())
					return -1;
				if(mgapTreatment->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A4:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: CallGapArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("CallGapArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int CallGapArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("CallGapArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case CallGapArg_GAPCRITERIA:
				if(asn1_tag_encode(160, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgapCriteria->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CallGapArg_GAPINDICATORS:
				if(asn1_tag_encode(161, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgapIndicators->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CallGapArg_CONTROLTYPE:
				if(asn1_tag_encode(130, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mcontrolType->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CallGapArg_GAPTREATMENT:
				if(asn1_tag_encode(163, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mgapTreatment->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case CallGapArg_EXTENSIONS:
				if(asn1_tag_encode(164, array) < 0)
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

int CallGapArg::Display(int tab){
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
			case CallGapArg_GAPCRITERIA:
			{
				printf(temp, " ", "gapCriteria");
				if(mgapCriteria->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CallGapArg_GAPINDICATORS:
			{
				printf(temp, " ", "gapIndicators");
				if(mgapIndicators->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CallGapArg_CONTROLTYPE:
			{
				printf(temp, " ", "controlType");
				if(mcontrolType->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CallGapArg_GAPTREATMENT:
			{
				printf(temp, " ", "gapTreatment");
				if(mgapTreatment->Display(tab+1) < 0)
					return -1;
				break;
			}
			case CallGapArg_EXTENSIONS:
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

bool CallGapArg::ValidateMandatory(char *errStr){
	if(NULL == mgapCriteria)
	{
		strcpy(errStr, "gapCriteria");
		return false;
	}
	else if(NULL == mgapIndicators)
	{
		strcpy(errStr, "gapIndicators");
		return false;
	}

	return true;
}
