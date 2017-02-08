#ifndef __GUI_H__
#define __GUI_H__

#include <cstdlib>
#include <string>
#include "drawable.h"


class GUI {
	private: 
		
        //GUI elements
        Fl_Window *win;
		Drawable *canvas;
        Fl_Input *pointXInput, *pointYInput;
        Fl_Button *addPointButton, *addPolygonButton;
        Fl_Button *arrangeExpandedButton, *arrangeContractedButton;
        Fl_Group *sidebar;
        Fl_Browser *browser;
        int lastSelectedLine;

        //Add a new polygon
		static void addPolygonCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->addPolygon();
		}

		void addPolygon(){
            canvas->polygons.addPolygon();
            redrawBrowser();
            lastSelectedLine = canvas->polygons.size();
            browser->deselect();
            browser->select(lastSelectedLine);
			canvas->redraw();
            
		}

        //Add a new point to the latest added polygon
        static void addPointCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->addPoint();
		}

		void  addPoint(){
            canvas->polygons.addPoint(atoi(pointXInput->value()), atoi(pointYInput->value()), browser->value() - 1);
            redrawBrowser();
            canvas->redraw();
		}
        
        //Draw the list of polygons in a browser
        void redrawBrowser(){
            lastSelectedLine = browser->value();
            browser->clear();

            for(size_t i = 0; i < canvas->polygons.size(); ++i){
                std::string color = "";
                browser->add((canvas->polygons.data[i].toText() + color).c_str());
            }

            browser->deselect();
            browser->select(lastSelectedLine);
        }

        //Arrange polygons so that they do not intersect
        static void arrangeExpandedCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->arrangeExpanded();
		}

        void arrangeExpanded(){
            canvas->polygons.arrangeExpanded();
            redrawBrowser();
            canvas->redraw();
        }

        //Arrange polygons so that they ocupy little space
        static void arrangeContractedCallback( Fl_Widget* o, void* data ) {
			((GUI*) data)->arrangeContracted();
		}

        void arrangeContracted(){
            canvas->polygons.arrangeContracted();
            redrawBrowser();
            canvas->redraw();
        }



	public:

		GUI(){
            lastSelectedLine = -1;
		}

		void init(){
			
			win = new Fl_Window ( 800,600,"Polygons" );
			win->begin();
				canvas = new Drawable (0, 0, 500, 600);

                //Add point to polygon
                sidebar = new  Fl_Group (500,0,300,600);
                    int x = 500;
                    int y = 0;
    				addPolygonButton = new Fl_Button (x+ 10, y + 10, 280, 50, "&Add new Polygon" );
                
				    addPointButton = new Fl_Button (x + 100,y + 70, 190, 50, "Add &Point To Polygon" );
                    pointXInput = new Fl_Input (x + 30,y + 75, 60, 20, "X");
                    pointYInput = new Fl_Input (x + 30,y + 95, 60, 20, "Y");

                    browser = new Fl_Browser(x + 5, y + 150, 290, 200, "Polygon list");

                    arrangeExpandedButton = new Fl_Button (x + 10, y + 380, 135, 40, "Arrange expanded");
                    arrangeContractedButton = new Fl_Button (x + 160, y + 380, 135, 40, "Arrange contracted");
                    sidebar->end();
			win->end();

            //Bind callbacks
			addPolygonButton->callback(  addPolygonCallback, this);
            addPointButton->callback(  addPointCallback, this);
            arrangeExpandedButton->callback( arrangeExpandedCallback, this);
            arrangeContractedButton->callback( arrangeContractedCallback, this);
            browser->type(FL_MULTI_BROWSER);

            //Styling
            canvas->box(FL_PLASTIC_DOWN_BOX);
            sidebar->box(FL_UP_BOX);
			canvas->color(FL_RED);
            win->resizable(canvas);

			//Buffer window
			Fl::visual(FL_DOUBLE|FL_INDEX);
			win->show();
					
			Fl::run();

		}
};

#endif