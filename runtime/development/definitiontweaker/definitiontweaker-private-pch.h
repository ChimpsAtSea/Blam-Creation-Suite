#pragma once

#include <platform/platform-public-pch.h>
#include <templatelibrary/templatelibrary-public-pch.h>
#include <shared/shared-public-pch.h>
#include <stringdefinitions/stringdefinitions-public-pch.h>
#include <cachefileserialization/cachefileserialization-public-pch.h>
#include <graphicslib/graphicslib-public-pch.h>
#include <symbolslib/symbolslib-public-pch.h>
#include <tagframework/tagframework-public-pch.h>
#include <tagdefinitions/tagdefinitions-public-pch.h>
#include <tagreflection/tagreflection-public-pch.h>
#include <tagvalidate/tagvalidate-public-pch.h>
#include <tagfileserialization/tagfileserialization-public-pch.h>
#include <highlevelcachefileserialization/highlevelcachefileserialization-public-pch.h>
#include <blamtoozle/blamtoozle-public-pch.h>
#include <runtimedefinitions/runtimedefinitions-public-pch.h>

#include "serializationcontexts/serialization_errors.h"
#include "serializationcontexts/serialization_context.h"
#include "serializationcontexts/group_serialization_context.h"
#include "serializationcontexts/tag_serialization_context.h"
#include "serializationcontexts/tag_data_serialization_context.h"
#include "serializationcontexts/tag_array_serialization_context.h"
#include "serializationcontexts/tag_block_serialization_context.h"
#include "serializationcontexts/tag_struct_serialization_context.h"
#include "serializationcontexts/tag_field_serialization_context.h"
#include "serializationcontexts/tag_resource_serialization_context.h"
#include "serializationcontexts/tag_api_interop_serialization_context.h"

#include "definition_tweaker.h"

#define MANDRILL_THEME_HIGH(v) { 0.502f, 0.075f, 0.256f, v }
#define MANDRILL_THEME_MED(v) { 0.455f, 0.198f, 0.301f, v }
#define MANDRILL_THEME_LOW(v) { 0.232f, 0.201f, 0.271f, v }
#define MANDRILL_THEME_DISABLED_HIGH(v) { 0.224f, 0.224f, 0.224f, v }
#define MANDRILL_THEME_DISABLED_MED(v) { 0.286f, 0.286f, 0.286f, v }
#define MANDRILL_THEME_DISABLED_LOW(v) { 0.215f, 0.215f, 0.215f, v }
#define MANDRILL_THEME_BG(v) { 0.200f, 0.220f, 0.270f, v }
#define MANDRILL_THEME_TEXT(v) { 0.930f, 0.965f, 0.945f, v }
#define MANDRILL_THEME_COMMENT_TEXT(v) { 0.752f, 0.965f, 0.766f, v }
#define MANDRILL_THEME_ERROR_TEXT(v) { 0.950f, 0.475f, 0.475f, v }
#define MANDRILL_THEME_WARNING_TEXT(v) { 0.937f, 0.796f, 0.467f, v }
#define MANDRILL_THEME_INFO_TEXT(v) { 0.796f, 0.808f, 0.965f, v }
#define MANDRILL_THEME_MENU(v) { 0.377f, 0.377f, 0.377f, v }

constexpr float MANDRILL_THEME_DEFAULT_TEXT_ALPHA = 0.78f;

#define THEME_FATAL_ERROR_TEXT(v) { 1.000f, 0.375f, 0.375f, v }
#define THEME_DATA_VALIDATION_OK_TEXT(v) { 0.796f, 0.965f, 0.808f, v }
#define THEME_BLOCK_VALIDATION_ERROR_TEXT(v) { 0.475f, 0.950f, 0.950f, v }
#define THEME_DATA_VALIDATION_ERROR_TEXT(v) { 0.950f, 0.475f, 0.950f, v } 

//                                                                                                     
//                                                       .^!!~:::.                                     
//                                                :~7?JYG#@@@@@@&#P~..                                 
//                                              ~P&@@@@@&#@@@@@@@@@&##BGJ.                             
//                                             ?##@@#GB#&@@&##&&&&&#&@@@&GJ                            
//                                            !#G@@BB&@@@@@&@&#@@@@@@@@@@@@G55J~                       
//                                           .P#BY?5?^^^^7!77!^^!5GP#@@@@@@@@@@@5.                     
//                                          .^^:                    .!P&@@@@&&##@J.                    
//                                          ^                          P@@@@&&&@@@B^                   
//                                         ~.                         ~#@@@&&&&##@@@!                  
//                                        ^:                           ~#@@&#&&@#&@@@~                 
//                                       ^:                             J@@@@@@@@@@@@&P:               
//                                      ^.               .             .?&@@@&&#BB#&@@Y                
//                                     ~?7!~~~~:^~!7?J5PB#PJ?77:        !@@@@##&@@&&#B.                
//                                     B@&@@@@@@&@@@@@@@@@@@@@@&#GPJ?!^.^#@@@&BG#@@@@B                 
//                                     ?@@@@@@@B^J@@@@@@@@@@@@@@@@?^!7?JYB@@@@&&@@@@B^                 
//                                     .&@@@@@!   J@@@@@@@@@@@@@@Y      .#@@&!?P@@@&:                  
//                                     ^P&@@@P     ?#@@@@@@@@#G?:       ~?Y57   J@@P                   
//                                       .~!!.      .~7?J?7!^.   . 7J:          ^@@^                   
//                                                              .57 ~5^    ~Y^  5@P                    
//                                        . ~JYYYYJ^             .G^ .:        J@5.                    
//                                  .:  ^?~ .^5&#Y?!   ~J!        ??          ?@?                      
//                                  ..  ^.     .        .~.        .     .  .5#~                       
//                                  .      .:^::::.               ?~  ^. !55&5.                        
//                                  :.    J#@@@@@&&#P?^          .B^  P^  :?&.                         
//                                   ^   Y@@@@@@@@@@@@@G!        7?   ^~^  PG                          
//                                   :^  5@@@#JJ5PPPPPPGB:           !P7BJ 7&Y                         
//                                    ~.  7PG5        ..             !^ :^:^~@B^                       
//                                    .^ ?PJ~^:::^~~!.        .7.  ?:    ^B^7@@&!                      
//                      :^^:.          :P^5#&&&&@@@@#~        5Y .55 ::: :!?@@@@@P!.                   
//                   :?G&@@&#GP5YYYYYY5B@J  .:^!7!^:        ^Y?  ~?!J5?:^5#@@@@@@@@&GJ~.               
//                :7P&@@@@@@@@@@@@@@@@@@@@7 :            ^7Y?:  ^JJ~  .J@@@@@@@@@@@@@@@#5!:            
//             :JB@@@@@@@@@@@@@@@@@@@@@@@@&??J!   ...:~?J7~::!JY?~..!Y&@@@@@@@@@@@@@@@@@@@&G?^         
//           ~P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@#5? ^!5G#BBP7J555J!~!YG&@@@@@@@@@@@@@@@@@@@@@@@@@@BJ^      
//         7B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y!5G&@@@@G!::!5B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B?:   
//       ~G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y  P@BJ~.7P&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5: 
//    ^YB@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@5... ^Y#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&?
// ~?G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@B7?B@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//  _______  _______  _______  _______  ______       __      _______  _______           _______  _______ 
// (  ____ \(  ____ )(  ____ \(  ____ \(  __  \     /__\    (  ____ )(  ___  )|\     /|(  ____ \(  ____ )
// | (    \/| (    )|| (    \/| (    \/| (  \  )   ( \/ )   | (    )|| (   ) || )   ( || (    \/| (    )|
// | (_____ | (____)|| (__    | (__    | |   ) |    \  /    | (____)|| |   | || | _ | || (__    | (____)|
// (_____  )|  _____)|  __)   |  __)   | |   | |    /  \/\  |  _____)| |   | || |( )| ||  __)   |     __)
//       ) || (      | (      | (      | |   ) |   / /\  /  | (      | |   | || || || || (      | (\ (   
// /\____) || )      | (____/\| (____/\| (__/  )  (  \/  \  | )      | (___) || () () || (____/\| ) \ \__
// \_______)|/       (_______/(_______/(______/    \___/\/  |/       (_______)(_______)(_______/|/   \__/
static inline const char* crazy_string_no_copy_hacktastic_function(
	std::string& runtime_string,
	void const* original_definition,
	const char* const& original_definition_name,
	bool& owns_name_memory /*nasty*/)
{
	if (original_definition && (original_definition_name == nullptr || strcmp(runtime_string.c_str(), original_definition_name) == 0))
	{
		owns_name_memory = false;
		return original_definition_name ? original_definition_name : "";
	}
	owns_name_memory = true;
	return runtime_string.c_str();
}
