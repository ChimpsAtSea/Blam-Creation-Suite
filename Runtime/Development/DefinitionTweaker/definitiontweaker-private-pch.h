#pragma once

#include <Platform\platform-public-pch.h>
#include <TemplateLibrary\templatelibrary-public-pch.h>
#include <StringDefinitions\stringdefinitions-public-pch.h>
#include <Shared\shared-public-pch.h>
#include <GraphicsLib\graphicslib-public-pch.h>
#include <Shared\Blam\blamlib-public-pch.h>
#include <TagDefinitions\tagdefinitions-public-pch.h>
#include <TagReflection\tagreflection-public-pch.h>
#include <TagValidate\tagvalidate-public-pch.h>
#include <TagFileSerialization\tagfileserialization-public-pch.h>
#include <MandrillLib\mandrilllib-public-pch.h>
#include <MandrillUI\mandrillui-public-pch.h>
#include <Blamtoozle\blamtoozle-public-pch.h>
#include <RuntimeDefinitions\runtimedefinitions-public-pch.h>

#include "Eldorado\file_last_modification_date.h"
#include "Eldorado\cache_file_tags_header.h"
#include "Eldorado\cache_file_tag_instance.h"
#include "Eldorado\strings_file_header.h"

#include "SerializationContexts\serialization_errors.h"
#include "SerializationContexts\serialization_context.h"
#include "SerializationContexts\group_serialization_context.h"
#include "SerializationContexts\tag_serialization_context.h"
#include "SerializationContexts\tag_data_serialization_context.h"
#include "SerializationContexts\tag_array_serialization_context.h"
#include "SerializationContexts\tag_block_serialization_context.h"
#include "SerializationContexts\tag_struct_serialization_context.h"
#include "SerializationContexts\tag_field_serialization_context.h"
#include "SerializationContexts\tag_resource_serialization_context.h"

#include "definition_tweaker.h"

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
static inline const char* crazy_no_string_copy_hacktastic_function(
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
