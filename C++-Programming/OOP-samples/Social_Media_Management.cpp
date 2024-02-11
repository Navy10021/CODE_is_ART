#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User {
    string username;
public:
    User(string username) : username(username) {}
    const string& getUsername() const { return username; }
};

class Comment {
    User* author;
    string text;
public:
    Comment(User* author, string text) : author(author), text(text) {}
    void display() const {
        cout << "  " << author->getUsername() << ": " << text << endl;
    }
};

class Post {
protected:
    static int nextId;
    int id;
    User* author;
    string content;
    vector<string> likes;
    vector<Comment*> comments;
public:
    Post(User* author, string content) : id(nextId++), author(author), content(content) {}
    virtual void display() const {
        cout << author->getUsername() << "'s Post (ID: " << id << "): " << content << endl;
        cout << "Likes: " << likes.size() << endl;
        cout << "Comments:" << endl;
        if (comments.empty()) {
            cout << "  No comments yet." << endl;
        } else {
            for (const auto& comment : comments) {
                comment->display();
            }
        }
    }
    void likePost(const string& username) { likes.push_back(username); }
    void addComment(Comment* comment) { comments.push_back(comment); }
    virtual ~Post() {
        for (auto* comment : comments) {
            delete comment; // Clean up comments
        }
    }
    static int getNextId() { return nextId; }
};
int Post::nextId = 1;

class TextPost : public Post {
public:
    TextPost(User* author, string content) : Post(author, content) {}
    void display() const override { Post::display(); }
};

class ImagePost : public Post {
    string imageUrl;
public:
    ImagePost(User* author, string content, string imageUrl)
        : Post(author, content), imageUrl(imageUrl) {}
    void display() const override {
        Post::display();
        cout << "Image URL: " << imageUrl << endl;
    }
};

class SocialMediaPlatform {
    vector<User> users;
    vector<Post*> posts;
public:
    ~SocialMediaPlatform() {
        for (auto* post : posts) {
            delete post; // Clean up posts
        }
    }
    void addPost(Post* post) { posts.push_back(post); }
    void displayPosts() const {
        for (const auto& post : posts) {
            post->display();
            cout << endl;
        }
    }
};

int main() {
    SocialMediaPlatform platform;

    User user1("john_doe");
    User user2("jane_smith");

    Post* textPost = new TextPost(&user1, "Hello, World!");
    Post* imagePost = new ImagePost(&user2, "Check out this cool photo!", "url_to_image.jpg");

    textPost->likePost(user2.getUsername());
    imagePost->addComment(new Comment(&user1, "Nice photo indeed!"));
    imagePost->likePost(user1.getUsername());

    platform.addPost(textPost);
    platform.addPost(imagePost);

    cout << "Social Media Posts:" << endl;
    platform.displayPosts();

    return 0;
}