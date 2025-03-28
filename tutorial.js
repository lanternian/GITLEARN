// Advanced JavaScript: A simple implementation of a Pub/Sub pattern

class PubSub {
    constructor() {
        this.events = {};
    }

    subscribe(event, callback) {
        if (!this.events[event]) {
            this.events[event] = [];
        }
        this.events[event].push(callback);
    }

    unsubscribe(event, callback) {
        if (!this.events[event]) return;

        this.events[event] = this.events[event].filter(cb => cb !== callback);
    }

    publish(event, data) {
        if (!this.events[event]) return;

        this.events[event].forEach(callback => callback(data));
    }
}

// Example usage:
const pubSub = new PubSub();

const onMessageReceived = (data) => {
    console.log(`Message received: ${data}`);
};

pubSub.subscribe('message', onMessageReceived);

pubSub.publish('message', 'Hello, World!'); // Logs: Message received: Hello, World!

pubSub.unsubscribe('message', onMessageReceived);

pubSub.publish('message', 'This will not be logged.');