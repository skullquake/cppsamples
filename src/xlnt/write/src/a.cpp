#include <iostream>
#include <xlnt/xlnt.hpp>
#include <vector>
#include <string>

int main()
{
    //Creating a 2 dimensional vector which we will write values to
    std::vector< std::vector<std::string> > wholeWorksheet;
    //Looping through each row (100 rows as per the second argument in the for loop)
    for (int outer = 0; outer < 100; outer++)
    {
        //Creating a fresh vector for a fresh row
	std::vector<std::string> singleRow;
	//Looping through each of the columns (100 as per the second argument in the for loop) in this particular row
	for(int inner = 0; inner < 100; inner++)
	{
	    //Adding a single value in each cell of the row 
	    std::string val = std::to_string(inner + 1);
	    singleRow.push_back(val);			
	}
	//Adding the single row to the 2 dimensional vector
	wholeWorksheet.push_back(singleRow);
	std::clog << "Writing to row " << outer << " in the vector " << std::endl;
    }
    //Writing to the spread sheet
    //Creating the output workbook 
    std::clog << "Creating workbook" << std::endl;
    xlnt::workbook wbOut;
    //Setting the destination output file name
    std::string dest_filename = "out/a.xlsx";
    //Creating the output worksheet
    xlnt::worksheet wsOut = wbOut.active_sheet();
    //Giving the output worksheet a title/name
    wsOut.title("data");
    //We will now be looping through the 2 dimensional vector which we created above
    //In this case we have two iterators one for the outer loop (row) and one for the inner loop (column)
    std::clog << "Looping through vector and writing to spread sheet" << std::endl;
    for (int fOut = 0; fOut < wholeWorksheet.size(); fOut++)
    {
        std::clog << "Row" << fOut << std::endl;
        for (int fIn = 0; fIn < wholeWorksheet.at(fOut).size(); fIn++)
        {
            //Take notice of the difference between accessing the vector and accessing the work sheet
	    //As you may already know Excel spread sheets start at row 1 and column 1 (not row 0 and column 0 like you would expect from a C++ vector) 
	    //In short the xlnt cell reference starts at column 1 row 1 (hence the + 1s below) and the vector reference starts at row 0 and column 0
	    wsOut.cell(xlnt::cell_reference(fIn + 1, fOut + 1)).value(wholeWorksheet.at(fOut).at(fIn));
	    //Further clarification to avoid confusion
	    //Cell reference arguments are (column number, row number); e.g. cell_reference(fIn + 1, fOut + 1)
	    //Vector arguments are (row number, column number); e.g. wholeWorksheet.at(fOut).at(fIn)
	}
    }
    std::clog << "Finished writing spread sheet" << std::endl;
    wbOut.save(dest_filename); 
    return 0;
}
