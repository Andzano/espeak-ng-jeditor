/*
 * eSpeakService.c
 *
 *  Created on: Feb 21, 2017
 *      Author: Marcis Majors
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include <jni.h>

// using include path to espeak-ng

#include <config.h>

#include <src/include/espeak-ng/speak_lib.h>
#include <src/include/espeak-ng/espeak_ng.h>


#include <src/libespeak-ng/error.h>
#include <src/libespeak-ng/phoneme.h>
#include <src/libespeak-ng/event.h>
#include <src/libespeak-ng/speech.h>
#include <src/libespeak-ng/espeak_command.h>
#include <src/libespeak-ng/fifo.h>
#include <src/libespeak-ng/sintab.h>
#include <src/libespeak-ng/mbrowrap.h>
#include <src/libespeak-ng/klatt.h>

#include <src/libespeak-ng/synthesize.h>
#include <src/libespeak-ng/spect.h>

#include "/home/marcis/workspace/eSpeak-Jedit/src/eSpeakServices_ESpeakService.h"

JNIEXPORT jstring JNICALL Java_eSpeakServices_ESpeakService_nativeGetEspeakNgVersion(JNIEnv * env, jobject jobj){

	/* if function is static then jobject points to class rather than object */

	const char* versionInfo = espeak_Info(NULL);

	jstring newString = (*env)->NewStringUTF(env, versionInfo);

	//jstring newString = (*env)->NewStringUTF(env, "Jeiiii!!!");

	return newString;
}

int main(){

	/*
	const char *data_path = NULL; //  use default path for espeak-data

	int samplerate;

	const char* versionInfo = espeak_Info(NULL);

	printf("Espeak version: %s\n", versionInfo);

	samplerate = espeak_Initialize(AUDIO_OUTPUT_PLAYBACK,0,data_path,0);

	printf("%i \n", samplerate);



	static char word[200] = "Hello World" ;
	strcpy(word, "Hello!");

	espeak_Synth( (char*) word, strlen(word)+1, 0, POS_CHARACTER, 0, espeakCHARS_AUTO, NULL, NULL);
	espeak_Synchronize();

	espeak_ERROR err = espeak_SetVoiceByName("latvian");

	if (err == EE_OK){
		printf("latvian voice selected\n");
	}

	espeak_Synth( (char*) word, strlen(word)+1, 0, POS_CHARACTER, 0, espeakCHARS_AUTO, NULL, NULL);
	espeak_Synchronize();

	const void **textptr;

	const void *someText = "Zirgs iet. Ko nu tagad?";

	printf("%s\n", (char*)someText);

	textptr = &someText;

	const char *phonemes = espeak_TextToPhonemes(textptr, espeakCHARS_AUTO, 0);

	printf("%s\n", (char*)*textptr);

	printf("%s\n", phonemes);

	phonemes = espeak_TextToPhonemes(textptr, espeakCHARS_AUTO, 0);

	printf("%s\n", (char*)*textptr);

	printf("%s\n", phonemes);

	*/

	/*

	SpectSeq *spect = SpectSeqCreate();

	LoadSpectSeq(spect, "/home/student/workspace-c/espeak-ng/phsource/vowel/a");

	printf("%s\n",spect->name);

	printf("%i\n", spect->duration);

	printf("%i\n",spect->numframes);

	printf("%i\n", spect->amplitude);

	SpectFrame *spectFrame;

	spectFrame = spect->frames[2];

	printf("%i\n", spectFrame->amp_adjust);

	SpectSeqDestroy(spect);





	espeak_Terminate();

	printf("Jei!\n");

	*/

	return 0;
}
