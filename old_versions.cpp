//#include <iostream>
//#include <vector>
//#include <stack>
//
//enum class OpenClose {
//	OPEN,
//	CLOSE
//};
//
//class Solution {
//public:
//	int longestValidParentheses(std::string s) {
//		if (!s.size()) return 0;
//		std::vector<int> seq_length;
//		std::vector<int> depth;
//		std::vector<OpenClose> type_par;
//		depth.reserve(static_cast<int>(s.size()));
//		for (int i = 0, depth_count = 0; i < static_cast<int>(s.size()); i++) {
//			if (s[i] == '(') {
//				depth_count++;
//				depth.push_back(depth_count);
//				type_par.push_back(OpenClose::OPEN);
//			}
//			else {
//				depth.push_back(depth_count);
//				depth_count--;
//				type_par.push_back(OpenClose::CLOSE);
//			}
//		}
//
//		std::stack<int> right_stack;
//		std::vector<int> lengths_substrs;
//		int curr_right_len = 1;
//		right_stack.push(depth[0]);
//		for (int i = 1; i < static_cast<int>(depth.size()); i++) {
//			if (right_stack.empty()) {
//				right_stack.push(depth[i]);
//				curr_right_len++;
//			}
//			else if (depth[i] > right_stack.top()) {
//				right_stack.push(depth[i]);
//				curr_right_len++;
//			}
//			else if (depth[i] == right_stack.top() && type_par[i] == OpenClose::CLOSE) {
//				right_stack.pop();
//				curr_right_len++;
//			}
//			else {
//				if (curr_right_len > 1)
//					lengths_substrs.push_back(curr_right_len);
//				right_stack = std::stack<int>();
//				if (i + 1 < depth.size())
//				{
//					curr_right_len = 1;
//					right_stack.push(depth[i + 1]);
//				}
//			}
//		}
//		curr_right_len -= right_stack.size();
//		if (curr_right_len == 1) curr_right_len = 0;
//		lengths_substrs.push_back(curr_right_len);
//
//		return *std::max_element(lengths_substrs.begin(), lengths_substrs.end());
//	}
//};
//
//int main()
//{
//	Solution sol;
//	int one = sol.longestValidParentheses("()(()");
//	std::cout << one << std::endl;
//}
