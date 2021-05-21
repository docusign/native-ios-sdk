//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2020 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

// The new fontSize scale, passed in as a string format parameter.
var scale = %f;

// Get all the elements in the document.
var allElements = document.getElementsByTagName("*");

for (var i=0, max=allElements.length; i < max; i++) {
    var element = allElements[i];
    
    // Only adjust elements with an existing fontSize.
    if (element.style.fontSize) {
        // Check if the fontSize has already been adjusted. The original fontSize (float value
        // should have been saved in the pdftron-fontSize entry.
        if (!element["pdftron-fontSize"]) {
            // No fontSize saved - save the original fontSize.
            element["pdftron-fontSize"] = parseFloat(element.style.fontSize);
        }
        
        // Scale the original fontSize by the specified scale.
        var newFontSize = (element["pdftron-fontSize"] * scale) + "pt";
        
        // Set the new scaled fontSize.
        element.style.fontSize = newFontSize;
    }
}
