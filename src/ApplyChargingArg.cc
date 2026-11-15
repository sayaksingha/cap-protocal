#include "ApplyChargingArg.h"

using namespace capphase3;

ApplyChargingArg::ApplyChargingArg()
{
	maChBillingChargingCharacteristics = NULL;
	partyToChargeDefault = new SendingSideID();
	partyToChargeDefault->setsendingSideID()->setValue("1");;
	mpartyToCharge = NULL;
	mextensions = NULL;
	mTagsPresent = 0;
	mTag = 0X0030;
	mTagArray = {0X0080, 0X00A2, 0X00A3};
	mTagOptional = {false, false, true};
}

ApplyChargingArg::~ApplyChargingArg()
{
	if(maChBillingChargingCharacteristics != NULL)
		delete maChBillingChargingCharacteristics;
	if(mpartyToCharge != NULL)
		delete mpartyToCharge;
	if(partyToChargeDefault != NULL)
		delete partyToChargeDefault;
	if(mextensions != NULL)
		delete mextensions;
}

CAMEL_AChBillingChargingCharacteristics* ApplyChargingArg::setaChBillingChargingCharacteristics(){
	if(maChBillingChargingCharacteristics == NULL)
	{
		maChBillingChargingCharacteristics = new CAMEL_AChBillingChargingCharacteristics();
		mTagsPresent |= ApplyChargingArg_ACHBILLINGCHARGINGCHARACTERISTICS;
		return maChBillingChargingCharacteristics;
	}
	else
		return maChBillingChargingCharacteristics;

}

bool ApplyChargingArg::setaChBillingChargingCharacteristics(CAMEL_AChBillingChargingCharacteristics* aChBillingChargingCharacteristics){
	if(maChBillingChargingCharacteristics == NULL)
	{
		return -1;
	}
	else
	{
		maChBillingChargingCharacteristics = aChBillingChargingCharacteristics;
		return true;
	}

}

SendingSideID* ApplyChargingArg::setpartyToCharge(){
	if(mpartyToCharge == NULL)
	{
		mpartyToCharge = new SendingSideID();
		mTagsPresent |= ApplyChargingArg_PARTYTOCHARGE;
		return mpartyToCharge;
	}
	else
		return mpartyToCharge;

}

bool ApplyChargingArg::setpartyToCharge(SendingSideID* partyToCharge){
	if(mpartyToCharge == NULL)
	{
		return -1;
	}
	else
	{
		mpartyToCharge = partyToCharge;
		return true;
	}

}

Extensions* ApplyChargingArg::setextensions(){
	if(mextensions == NULL)
	{
		mextensions = new Extensions();
		mTagsPresent |= ApplyChargingArg_EXTENSIONS;
		return mextensions;
	}
	else
		return mextensions;

}

bool ApplyChargingArg::setextensions(Extensions* extensions){
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

CAMEL_AChBillingChargingCharacteristics* ApplyChargingArg::getaChBillingChargingCharacteristics() {//throw(const char*)
	if(NULL == maChBillingChargingCharacteristics)
		throw("Object aChBillingChargingCharacteristics is NULL");
	else
		return maChBillingChargingCharacteristics;
}

SendingSideID* ApplyChargingArg::getpartyToCharge() {//throw(const char*)
	if(NULL == mpartyToCharge)
		throw("Object partyToCharge is NULL");
	else
		return mpartyToCharge;
}

Extensions* ApplyChargingArg::getextensions() {//throw(const char*)
	if(NULL == mextensions)
		throw("Object extensions is NULL");
	else
		return mextensions;
}

bool ApplyChargingArg::isPresent(int tag){
	return (mTagsPresent & tag)?true:false;
}

int ApplyChargingArg::Decode(capstd::byteArray *array, unsigned *bytesParsed, bool lengthDecode){
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
			case 0X0080:
				if(NULL == this->setaChBillingChargingCharacteristics())
					return -1;
				if(maChBillingChargingCharacteristics->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A2:
				if(NULL == this->setpartyToCharge())
					return -1;
				if(mpartyToCharge->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			case 0X00A3:
				if(NULL == this->setextensions())
					return -1;
				if(mextensions->Decode(array, &bytesDecoded) < 0)
					decode = false;
				break;
			default:
				printf("Unknown Tag received in Datatype: ApplyChargingArg Tag:%d Offset:%d\n", tag, array->offset);
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
		printf("ApplyChargingArg: Mandatory Tag:%s Missing Decode Failed\n", errStr);
		return -1;
	}

	return 1;
}
int ApplyChargingArg::Encode(capstd::byteArray *array){
	unsigned lTemp = 0;
	unsigned lSwitchTemp = 0;
	unsigned tagsPresent = mTagsPresent;
	bool lIndefinite = false;
	unsigned lLengthOffset = 0;

	char errStr[50]="";
	if(false == this->ValidateMandatory(errStr))
	{
		printf("ApplyChargingArg: Mandatory Tag:%s not set Encode Failed\n", errStr);
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
			case ApplyChargingArg_ACHBILLINGCHARGINGCHARACTERISTICS:
				if(asn1_tag_encode(128, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((maChBillingChargingCharacteristics->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ApplyChargingArg_PARTYTOCHARGE:
				if(asn1_tag_encode(162, array) < 0)
					return -1;
				lengthOffset = array->offset++;
				if((mpartyToCharge->Encode(array) < 0) || 
					(asn1_length_encode(lengthOffset, array, &lIndefinite) < 0))
					return -1;
				break;
			case ApplyChargingArg_EXTENSIONS:
				if(asn1_tag_encode(163, array) < 0)
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

int ApplyChargingArg::Display(int tab){
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
			case ApplyChargingArg_ACHBILLINGCHARGINGCHARACTERISTICS:
			{
				printf(temp, " ", "aChBillingChargingCharacteristics");
				if(maChBillingChargingCharacteristics->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ApplyChargingArg_PARTYTOCHARGE:
			{
				printf(temp, " ", "partyToCharge");
				if(mpartyToCharge->Display(tab+1) < 0)
					return -1;
				break;
			}
			case ApplyChargingArg_EXTENSIONS:
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

bool ApplyChargingArg::ValidateMandatory(char *errStr){
	if(NULL == maChBillingChargingCharacteristics)
	{
		strcpy(errStr, "aChBillingChargingCharacteristics");
		return false;
	}
	else if(NULL == mpartyToCharge)
	{
		strcpy(errStr, "partyToCharge");
		return false;
	}

	return true;
}
