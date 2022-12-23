#pragma once

#define WAVE_FORMAT_XMA2 0x166

typedef struct XMA2WAVEFORMATEX
{
	WAVEFORMATEX wfx;
	// Meaning of the WAVEFORMATEX fields here:
	//    wFormatTag;        // Audio format type; always WAVE_FORMAT_XMA2
	//    nChannels;         // Channel count of the decoded audio
	//    nSamplesPerSec;    // Sample rate of the decoded audio
	//    nAvgBytesPerSec;   // Used internally by the XMA encoder
	//    nBlockAlign;       // Decoded sample size; channels * wBitsPerSample / 8
	//    wBitsPerSample;    // Bits per decoded mono sample; always 16 for XMA
	//    cbSize;            // Size in bytes of the rest of this structure (34)

	WORD  NumStreams;        // Number of audio streams (1 or 2 channels each)
	DWORD ChannelMask;       // Spatial positions of the channels in this file,
							 // stored as SPEAKER_xxx values (see audiodefs.h)
	DWORD SamplesEncoded;    // Total number of PCM samples the file decodes to
	DWORD BytesPerBlock;     // XMA block size (but the last one may be shorter)
	DWORD PlayBegin;         // First valid sample in the decoded audio
	DWORD PlayLength;        // Length of the valid part of the decoded audio
	DWORD LoopBegin;         // Beginning of the loop region in decoded sample terms
	DWORD LoopLength;        // Length of the loop region in decoded sample terms
	BYTE  LoopCount;         // Number of loop repetitions; 255 = infinite
	BYTE  EncoderVersion;    // Version of XMA encoder that generated the file
	WORD  BlockCount;        // XMA blocks in file (and entries in its seek table)
} XMA2WAVEFORMATEX, * PXMA2WAVEFORMATEX;
