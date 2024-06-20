struct student* create_list();
void print_list(struct student* head);
int get_num_of_nodes(struct student* head);
struct student* insert_at_beginning(struct student* head, struct student* new_node);
struct student* insert_at_end(struct student* head, struct student* new_node);
struct student* delete_by_id(struct student* head, int id);
struct student* delete_by_name(struct student* head, char name[100]);
void sort_by_gpa(struct student** head_ref);