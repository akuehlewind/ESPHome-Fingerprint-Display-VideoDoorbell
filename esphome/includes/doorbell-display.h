#include "esphome.h"

class DisplayPanel : public Component {
    public:
        void DrawWeatherIcon (display::Display *buff, std::string weatherState ) {
            std::map<std::string, std::string> weather_icon_map
            {
              {"cloudy", "\U000F0590"},
              {"cloudy-alert", "\U000F0F2F"},
              {"cloudy-arrow-right", "\U000F0E6E"},
              {"fog", "\U000F0591"},
              {"hail", "\U000F0592"},
              {"hazy", "\U000F0F30"},
              {"hurricane", "\U000F0898"},
              {"lightning", "\U000F0593"},
              {"lightning-rainy", "\U000F067E"},
              {"night", "\U000F0594"},
              {"night-partly-cloudy", "\U000F0F31"},
              {"partlycloudy", "\U000F0595"},
              {"partly-lightning", "\U000F0F32"},
              {"partly-rainy", "\U000F0F33"},
              {"partly-snowy", "\U000F0F34"},
              {"partly-snowy-rainy", "\U000F0F35"},
              {"pouring", "\U000F0596"},
              {"rainy", "\U000F0597"},
              {"snowy", "\U000F0598"},
              {"snowy-heavy", "\U000F0F36"},
              {"snowy-rainy", "\U000F067F"},
              {"sunny", "\U000F0599"},
              {"sunny-alert", "\U000F0F37"},
              {"sunny-off", "\U000F14E4"},
              {"sunset", "\U000F059A"},
              {"sunset-down", "\U000F059B"},
              {"sunset-up", "\U000F059C"},
              {"tornado", "\U000F0F38"},
              {"windy", "\U000F059D"},
              {"windy-variant", "\U000F059E"},
            };
            
             // Weather Icon
            std::string weatherIcon = weather_icon_map[weatherState];
            
            if(!weatherIcon.empty()) {
                buff->printf(buff->get_width()/2 + 50, 318, &id(weather_icons),Color::WHITE, TextAlign::BOTTOM_CENTER, "%s", weatherIcon.c_str());   
            }
        }
        
         void DrawWeatherTemp (display::Display *buff, float temp) { 
            if (!isnan(temp)) {
                buff->printf(buff->get_width()-5, 318, &id(bar_text),Color::WHITE, TextAlign::BOTTOM_RIGHT, "%.0f°C", temp);   
            }
         }
         
         void DrawStatusIcons (display::Display *buff, bool mailbox ,std::string garage_door , bool alarm_trigger ) {
            // Status Icons
            std::string icons = "";      
            std::string mailIcon = "";
            std::string garageIcon = "";
    
            // Mailbox Icon
            if (mailbox) {
                icons = icons + "\U0000e0be";
            }
    
            // Garagedoor Icon
            std::map<std::string, std::string> garage_state { 
                { "closed", "" },
                { "open", "\U0000e82d" },
            };
            if(!garage_door.empty()) {
                icons = icons + garage_state[garage_door];
            }

            // Alarm Trigger Icon
            if (alarm_trigger) {
                icons = icons + "\U0000e002";
            }
    
            buff->printf(5, 320, &id(materialdesign_icons_25), TextAlign::BOTTOM_LEFT, icons.c_str());   
         }
};