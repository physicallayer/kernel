#include "rulemanager.h"

void readRule(Rule* inbound, Rule* outbound)
{
    struct file* in_rule_file = fileOpen(_IN_RULE, O_RDONLY, 0);
    struct file* out_rule_file = fileOpen(_IN_RULE, O_RDONLY, 0);

    int in_size = getWholeSize(_IN_RULE);
    int out_size = getWholeSize(_OUT_RULE);

    unsigned char* in_rule_data, out_rule_data;

    readFile(in_rule_data, 0, in_rule_data, in_size);
    readFile(out_rule_data, 0, out_rule_data, out_size);

    int lineCount = getLineCount(in_rule_data, in_size);

    inbound = (Rule*)kmalloc(lineCount * sizeof(Rule), GFP_KERNEL);

    int charIndex = 0;
    for(int i = 0; i< lineCount; i++)
    {
        int currIndex = 0;
        while(in_rule_data[charIndex + currIndex] != 0x20 || in_rule_data[charIndex + currIndex] != 0x0)
        {
            currIndex++;
        }
        charIndex += currIndex;

    }
}
