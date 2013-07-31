#include "../include/FileWriterBase.h"

using namespace openshot;

// Initialize the values of the FileInfo struct
void FileWriterBase::InitFileInfo()
{
	info.has_video = false;
	info.has_audio = false;
	info.duration = 0.0;
	info.file_size = 0;
	info.height = 0;
	info.width = 0;
	info.pixel_format = -1;
	info.fps = Fraction();
	info.video_bit_rate = 0;
	info.pixel_ratio = Fraction();
	info.display_ratio = Fraction();
	info.vcodec = "";
	info.video_length = 0;
	info.video_stream_index = -1;
	info.video_timebase = Fraction();
	info.interlaced_frame = false;
	info.top_field_first = true;
	info.acodec = "";
	info.audio_bit_rate = 0;
	info.sample_rate = 0;
	info.channels = 0;
	info.audio_stream_index = -1;
	info.audio_timebase = Fraction();
}

// This method copy's the info struct of a reader, and sets the writer with the same info
void FileWriterBase::CopyReaderInfo(FileReaderBase* reader)
{
	info.has_video = reader->info.has_video;
	info.has_audio = reader->info.has_audio;
	info.duration = reader->info.duration;
	info.file_size = reader->info.file_size;
	info.height = reader->info.height;
	info.width = reader->info.width;
	info.pixel_format = reader->info.pixel_format;
	info.fps.num = reader->info.fps.num;
	info.fps.den = reader->info.fps.den;
	info.video_bit_rate = reader->info.video_bit_rate;
	info.pixel_ratio.num = reader->info.pixel_ratio.num;
	info.pixel_ratio.den = reader->info.pixel_ratio.den;
	info.display_ratio.num = reader->info.display_ratio.num;
	info.display_ratio.den = reader->info.display_ratio.den;
	info.vcodec = reader->info.vcodec;
	info.video_length = reader->info.video_length;
	info.video_stream_index = reader->info.video_stream_index;
	info.video_timebase.num = reader->info.video_timebase.num;
	info.video_timebase.den = reader->info.video_timebase.den;
	info.interlaced_frame = reader->info.interlaced_frame;
	info.top_field_first = reader->info.top_field_first;
	info.acodec = reader->info.acodec;
	info.audio_bit_rate = reader->info.audio_bit_rate;
	info.sample_rate = reader->info.sample_rate;
	info.channels = reader->info.channels;
	info.audio_stream_index = reader->info.audio_stream_index;
	info.audio_timebase.num = reader->info.audio_timebase.num;
	info.audio_timebase.den = reader->info.audio_timebase.den;
}

// Display file information
void FileWriterBase::DisplayInfo() {
	cout << fixed << setprecision(2) << boolalpha;
	cout << "----------------------------" << endl;
	cout << "----- File Information -----" << endl;
	cout << "----------------------------" << endl;
	cout << "--> Has Video: " << info.has_video << endl;
	cout << "--> Has Audio: " << info.has_audio << endl;
	cout << "--> Duration: " << info.duration << " Seconds" << endl;
	cout << "--> File Size: " << double(info.file_size) / 1024 / 1024 << " MB" << endl;
	cout << "----------------------------" << endl;
	cout << "----- Video Attributes -----" << endl;
	cout << "----------------------------" << endl;
	cout << "--> Width: " << info.width << endl;
	cout << "--> Height: " << info.height << endl;
	cout << "--> Pixel Format: " << info.pixel_format << endl;
	cout << "--> Frames Per Second: " << info.fps.ToDouble() << " (" << info.fps.num << "/" << info.fps.den << ")" << endl;
	cout << "--> Video Bit Rate: " << info.video_bit_rate/1000 << " kb/s" << endl;
	cout << "--> Pixel Ratio: " << info.pixel_ratio.ToDouble() << " (" << info.pixel_ratio.num << "/" << info.pixel_ratio.den << ")" << endl;
	cout << "--> Display Aspect Ratio: " << info.display_ratio.ToDouble() << " (" << info.display_ratio.num << "/" << info.display_ratio.den << ")" << endl;
	cout << "--> Video Codec: " << info.vcodec << endl;
	cout << "--> Video Length: " << info.video_length << " Frames" << endl;
	cout << "--> Video Stream Index: " << info.video_stream_index << endl;
	cout << "--> Video Timebase: " << info.video_timebase.ToDouble() << " (" << info.video_timebase.num << "/" << info.video_timebase.den << ")" << endl;
	cout << "--> Interlaced: " << info.interlaced_frame << endl;
	cout << "--> Interlaced: Top Field First: " << info.top_field_first << endl;
	cout << "----------------------------" << endl;
	cout << "----- Audio Attributes -----" << endl;
	cout << "----------------------------" << endl;
	cout << "--> Audio Codec: " << info.acodec << endl;
	cout << "--> Audio Bit Rate: " << info.audio_bit_rate/1000 << " kb/s" << endl;
	cout << "--> Sample Rate: " << info.sample_rate << " Hz" << endl;
	cout << "--> # of Channels: " << info.channels << endl;
	cout << "--> Audio Stream Index: " << info.audio_stream_index << endl;
	cout << "--> Audio Timebase: " << info.audio_timebase.ToDouble() << " (" << info.audio_timebase.num << "/" << info.audio_timebase.den << ")" << endl;
	cout << "----------------------------" << endl;
}

