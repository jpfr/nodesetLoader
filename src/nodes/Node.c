/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 *    Copyright 2020 (c) Matthias Konnerth
 */

#include "Node.h"
#include "DataTypeNode.h"
#include <stdlib.h>
#include "../Value.h"

NL_Node *Node_new(NL_NodeClass nodeClass)
{
    NL_Node *node = NULL;
    switch (nodeClass)
    {
    case NODECLASS_VARIABLE:
        node = (NL_Node *)calloc(1, sizeof(NL_VariableNode));
        break;
    case NODECLASS_OBJECT:
        node = (NL_Node *)calloc(1, sizeof(NL_ObjectNode));
        break;
    case NODECLASS_OBJECTTYPE:
        node = (NL_Node *)calloc(1, sizeof(NL_ObjectTypeNode));
        break;
    case NODECLASS_REFERENCETYPE:
        node = (NL_Node *)calloc(1, sizeof(NL_ReferenceTypeNode));
        break;
    case NODECLASS_VARIABLETYPE:
        node = (NL_Node *)calloc(1, sizeof(NL_VariableTypeNode));
        break;
    case NODECLASS_DATATYPE:
        node = (NL_Node *)calloc(1, sizeof(NL_DataTypeNode));
        break;
    case NODECLASS_METHOD:
        node = (NL_Node *)calloc(1, sizeof(NL_MethodNode));
        break;
    case NODECLASS_VIEW:
        node = (NL_Node *)calloc(1, sizeof(NL_ViewNode));
        break;
    }
    if(!node)
    {
        return NULL;
    }
    return node;
}

static void deleteRef(NL_Reference *ref)
{
    while (ref)
    {
        NL_Reference *tmp = ref->next;
        UA_NodeId_clear(&ref->target);
        UA_NodeId_clear(&ref->refType);
        free(ref);
        ref = tmp;
    }
}

void Node_delete(NL_Node *node)
{
    UA_NodeId_clear(&node->id);
    deleteRef(node->hierachicalRefs);
    deleteRef(node->nonHierachicalRefs);
    if (node->nodeClass == NODECLASS_DATATYPE)
    {
        DataTypeNode_clear((NL_DataTypeNode *)node);
    }
    if(node->nodeClass == NODECLASS_VARIABLE)
    {
        NL_VariableNode* varNode = (NL_VariableNode*)node;
        free(varNode->refToTypeDef);
        if(varNode->value)
        {
            Value_delete(varNode->value);
        }
    }
    if(node->nodeClass==NODECLASS_OBJECT)
    {
        NL_ObjectNode *objNode = (NL_ObjectNode *)node;
        free(objNode->refToTypeDef);
    }
    free(node);
}
