/**
 * @file
 * @brief Source file for De-interlace class
 * @author Jonathan Thomas <jonathan@openshot.org>
 *
 * @section LICENSE
 *
 * Copyright (c) 2008-2013 OpenShot Studios, LLC
 * (http://www.openshotstudios.com). This file is part of
 * OpenShot Library (http://www.openshot.org), an open-source project
 * dedicated to delivering high quality video editing and animation solutions
 * to the world.
 *
 * OpenShot Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenShot Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenShot Library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../include/effects/Deinterlace.h"

using namespace openshot;

// Default constructor
Deinterlace::Deinterlace(bool UseOddLines) : isOdd(UseOddLines)
{
	/// Initialize the values of the EffectInfo struct.
	InitEffectInfo();

	/// Set the effect info
	info.name = "Deinterlace";
	info.description = "Remove interlacing from a video (i.e. even or odd horizontal lines)";
	info.has_audio = false;
	info.has_video = true;
}

// This method is required for all derived classes of EffectBase, and returns a
// modified openshot::Frame object
tr1::shared_ptr<Frame> Deinterlace::GetFrame(tr1::shared_ptr<Frame> frame, int frame_number)
{
	// Calculate the new size (used to shrink and expand the image, to remove interlacing)
	Magick::Geometry original_size = frame->GetImage()->size();
	Magick::Geometry frame_size = frame->GetImage()->size();
	frame_size.aspect(false); // allow the image to be re-sized to an invalid aspect ratio
	frame_size.height(frame_size.height() / 2.0); // height set to 50% of original height

	if (isOdd)
		// Roll the image by 1 pixel, to use the ODD horizontal lines (instead of the even ones)
		frame->GetImage()->roll(0,1);

	// Resample the image to 50% height (to remove every other line)
	frame->GetImage()->sample(frame_size);

	// Resize image back to original height
	frame->GetImage()->resize(original_size);

	// return the modified frame
	return frame;
}
