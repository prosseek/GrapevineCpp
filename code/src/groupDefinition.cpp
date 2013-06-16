#include "groupUtils.h"
#include "util.h"
#include "groupDefinition.h"

void GroupDefinition::handleContextSummary(GroupContextSummary& currentGroupSummary, const ContextSummary& newSummary)
{
    int uid = newSummary.getId();
    int gid = currentGroupSummary.getId();
    
    vector<int> groupIds;
    GroupUtils::getDeclaredMemberships(newSummary, groupIds);
    vector<int> memberIds;
    currentGroupSummary.getMemberIds(memberIds);
    if (Util::in(groupIds, gid)) 
    {
        if (!Util::in(memberIds, uid)) // uid not in 
            currentGroupSummary.addMemberId(uid);
    }
}

void GroupDefinition::handleGroupSummary(GroupContextSummary& currentGroupSummary, const GroupContextSummary& newSummary)
{
    vector<int> memberIds;
    currentGroupSummary.getMemberIds(memberIds);
    vector<int> newMemberIds;
    newSummary.getMemberIds(newMemberIds);
    
    Util::removeAll(newMemberIds, memberIds); // the newMemberIds holds the result
    currentGroupSummary.addMemberIds(newMemberIds);
}
