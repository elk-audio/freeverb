// Macro for killing denormalled numbers
//
// Written by Jezar at Dreampoint, June 2000
// http://www.dreampoint.co.uk
// Based on IS_DENORMAL macro by Jon Watte
// This code is public domain

#ifndef _denormals_
#define _denormals_

#ifdef FREEVERB_UNDENORMALIZE
    #define undenormalise(sample) if(((*(unsigned int*)&sample)&0x7f800000)==0) sample=0.0f
#else
    #define undenormalise(sample)
#endif // FREEVERB_UNDENORMALIZE

#endif//_denormals_

//ends
