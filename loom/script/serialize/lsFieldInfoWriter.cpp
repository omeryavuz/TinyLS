/*
 * ===========================================================================
 * Loom SDK
 * Copyright 2011, 2012, 2013
 * The Game Engine Company, LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * ===========================================================================
 */

#include "loom/script/serialize/lsFieldInfoWriter.h"

namespace LS {
json_t *FieldInfoWriter::write()
{
    json_t *json = json_object();

    MemberInfoWriter::write(json);

    json_object_set(json, "type", json_string(fullTypeName.c_str()));

    json_t *fattr = json_array();

    json_object_set(json, "fieldattributes", fattr);

    if (attr.isNative)
    {
        json_array_append(fattr, json_string("native"));
    }
    if (attr.isPublic)
    {
        json_array_append(fattr, json_string("public"));
    }
    if (attr.isPrivate)
    {
        json_array_append(fattr, json_string("private"));
    }
    if (attr.isProtected)
    {
        json_array_append(fattr, json_string("protected"));
    }
    if (attr.isStatic)
    {
        json_array_append(fattr, json_string("static"));
    }
    if (attr.isConst)
    {
        json_array_append(fattr, json_string("const"));
    }

    if (templateInfo)
    {
        json_object_set(json, "templatetypes", writeTemplateTypeInfo(templateInfo));
    }
    else
    {
        json_object_set(json, "templatetypes", json_null());
    }

    return json;
}
}
