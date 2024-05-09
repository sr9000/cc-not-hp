# "Clean" Code, (not) Horrible Performance

> **TL; DR**: It is always tradeoff between comfort & performance. ⚖️
> 
> Nothing new, folks! Keep working hard ;)

Hi, Stepan is here. I'm an expirenced cpp developer, and I <u>*love*</u> to optimize the code ;)

After wathcing a 📽️ "Clean" Code, Horrible Performance, I found Casey's final thouts quite opposite to my expirience.

[!["Clean" Code, Horrible Performance](https://img.youtube.com/vi/tD5NrevFtbU/0.jpg)](https://www.youtube.com/watch?v=tD5NrevFtbU)

# Code instead of words

This repo contains two listings of code from the article [Computer, Enhance! - "Clean" Code, Horrible Performance](https://www.computerenhance.com/p/clean-code-horrible-performance).

1. [cc.hpp](https://github.com/sr9000/cc-not-hp/blob/main/code/cc.hpp) - Clean code version (LISTING 22-23 in the article)
2. [cm.hpp](https://github.com/sr9000/cc-not-hp/blob/main/code/cm.hpp) - Casey Muratori version, struct with enum (LISTING 25, 27 in the article)

Obviously, plain structs would be faster, than classes, because there is no double-derefference of pointers, and also same formula used for every shape.

> LET'S RUN IT!

I've got following 🍌 banana-numbers on my `Intel(R) Core(TM) i5-8400 CPU @ 2.80GHz`:

| Version        | Debug build:                                                    | Release build (-O2):                                            |
| -------------- | --------------------------------------------------------------- | --------------------------------------------------------------- |
| CLEAN CODE     | <pre>init    42.1204 ns/shape<br>calc    5.75511 ns/shape</pre> | <pre>init    36.8053 ns/shape<br>calc    3.17421 ns/shape</pre> |
| CASEY MURATORI | <pre>init    8.81836 ns/shape<br>calc    2.89415 ns/shape</pre> | <pre>init    6.85333 ns/shape<br>calc    1.03924 ns/shape</pre> |

# Yes, and no (:

Yes, as expected Release is faster, than Debug.
Yes, as expected plain structs are faster, than classes.
<u>**NO**</u>, there is no 15-20 factor in the performance difference.

I didn't try to say that making code 3 times faster are useless, but let's compare in details, what we get, and what we loose.

# Comparison

In comparing the CLEAN CODE (CC) and CASEY MURATORI's CODE (CM), we can observe several trade-offs between the two approaches:

**CLEAN CODE (CC):**
CC adheres to object-oriented programming principles, offering a polymorphic structure that is highly extensible and maintainable. It allows for the easy addition of new shapes with distinct behaviors, such as bezier-curved figures, and encapsulates properties within each class, ensuring that related information is cohesively organized.

**Pros:**

- **Maintainability:** The polymorphic design simplifies the addition of new shapes and behaviors.
- **Encapsulation:** Each shape's properties and behaviors are self-contained, promoting code clarity and cohesion.

**Cons:**

- **Performance:** Slower execution and higher memory usage due to polymorphism.
- **Complexity:** The use of double-pointers for polymorphism adds a layer of complexity.

**CASEY MURATORI's CODE (CM):**
CM prioritizes performance, achieving faster initialization and calculation times. It utilizes a constant table approach, which results in a faster and simpler codebase.

**Pros:**

- **Performance:** CM is approximately three times faster in calculations and six times faster in initialization compared to CC.
- **Simplicity:** The code is less complex due to the absence of virtual functions.

**Cons:**

- **Scalability:** Adding new shapes with different area calculation formulas requires updating the constant table and can lead to errors if not managed carefully.
- **Hardcoding:** The reliance on a constant table and specific shape structure limits the code's flexibility and extensibility, making it harder to introduce radically different shapes.
- **Extensibility:** CM's design limits its use as a standalone library and loses idiomatic elegance when implementing new behaviors like perimeter calculations.

# Final thoughts 💬

> ⚠️ DICLAIMER: The final thoughts presented in this page were crafted with the assistance of an advanced AI to enhance the clarity and expression of ideas.

In the pursuit of crafting software, we often find ourselves at a crossroads, where the path of performance diverges from that of maintainability. It's a juncture well-known to those of us who've navigated the complexities of optimization.

The principles we hold dear — be it KISS, DRY, or SOLID — are not dogmas to be followed blindly. They are beacons that guide us, yet they do not dictate our journey. As the wise adage goes, "Only Sith deal in absolutes", and in our world, the absolute pursuit of optimization without consideration for the bigger picture can indeed be a folly.

Optimization should come not as a premature endeavor but as a thoughtful refinement, a process that begins once the architecture has been laid out with clarity and simplicity, addressing the high-level needs.

It's a known truth that optimization can cause the minutiae of implementation to seep into our abstractions. This is why the most optimized corridors of our codebases are often the most heavily commented and documented. It's also why business logic, bound by I/O, remains pristine and unoptimized, its cleanliness preserving the potential for future extension.

When we speak of optimization, our thoughts turn to realms where performance is paramount — OpenGL, LAPACK, CUDA. Each problem we encounter deserves a tool fashioned for its resolution.

Yet, in the modern landscape of software, we encounter performance issues that are not always detrimental.

*Consider the myriad single-purpose applications* — calculators, to-do lists, calendars. Their rapid development, perhaps via an Electron-based approach, leads to larger footprints, but the vast storage and memory of today's hardware scarcely register the difference.

*Actively developed software*, driven by economic forces, may succumb to feature creep, with performance taking a backseat. However, the features that capture the users' favor are invariably honed and optimized over time.

*Cross-platform solutions*, like the tkinter GUI, may be criticized for their sluggishness and size, but their goal is ultimate portability and ease of use, a noble pursuit in its own right.

*The true challenge arises* when simplicity is abused — when low-code solutions are stretched beyond their intended scope, leading to scalability challenges. This is the pitfall we must guard against, the 'root of evil' in our endeavors.

As developers, we must recognize that every choice carries weight. The key lies in understanding the demands of our project and selecting the path that aligns with our goals. **Performance and maintainability are not mutually exclusive, but rather two sides of the same coin**, and it is our task to strike the right balance for the task at hand


