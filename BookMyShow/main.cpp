#include "repositories/BookingRepository.h"
#include "repositories/MovieRepository.h"
#include "repositories/SeatRepository.h"
#include "repositories/ShowRepository.h"
#include "repositories/TheatreRepository.h"
#include "repositories/UserRepository.h"
#include "services/BookingService.h"
#include "services/MovieService.h"
#include "services/PaymentService.h"
#include "services/SeatService.h"
#include "services/ShowService.h"
#include "services/TheatreService.h"
#include "services/UserService.h"
#include "factories/SeatFactory.h"

int main()
{
    UserRepository userRepo;
    BookingRepository bookingRepo;
    MovieRepository movieRepo;
    SeatRepository seatRepo;
    ShowRepository showRepo;
    TheatreRepository theareRepo;

    UserService *userService = new UserService(&userRepo);
    TheatreService *theatreService = new TheatreService(&theareRepo);
    ShowService *showService = new ShowService(&showRepo, &seatRepo);
    SeatService *seatService = new SeatService(&seatRepo);
    PaymentService *paymentService = new PaymentService();
    MovieService *movieService = new MovieService(&movieRepo);
    BookingService *bookingService = new BookingService(&bookingRepo, showService, paymentService);

    SeatFactory *seatFactory = new SeatFactory();

    // User Creation //
    User *user1 = userService->createUser("Raj Lakhera", "rajlakhera@gmail.com", "3433434332");

    // Theatre Creation //
    Theatre *t1 = theatreService->createTheatre("C21", "Vijay Nagar");

    // Premium Seat Creation //
    for (int i = 0; i < 5; i++)
    {
        Seat *s = seatService->createSeat("premium", "A" + to_string(i));
        t1->addSeats(s);
    }

    // Recliner Seat Creation //
    for (int i = 0; i < 10; i++)
    {
        Seat *s = seatService->createSeat("recliner", "A" + to_string(i));
        t1->addSeats(s);
    }

    // Normal Seat Creation //
    for (int i = 0; i < 20; i++)
    {
        Seat *s = seatService->createSeat("normal", "A" + to_string(i));
        t1->addSeats(s);
    }

    // Movie Creation //
    Movie *m1 = movieService->addMovie("Doomsday", "New avengers movie", "en", "17/12/2026", "03:00:00");

    Show *s1 = showService->createShow(m1, t1, "01:00 PM", "04:30 PM", "17/12/2026");

    for (Seat *s : t1->getSeats())
    {
        int price = s->getSeatType() == SeatType::NORMAL ? 500 : s->getSeatType() == SeatType::RECLINER ? 1000
                                                                                                        : 1500;
        s1->addShowSeat(new ShowSeat(s, price));
    }

    vector<ShowSeat *> selectedSeats;
    selectedSeats.push_back(s1->getShowSeats()[0]);
    selectedSeats.push_back(s1->getShowSeats()[1]);

    Booking *booking = bookingService->createBooking(
        user1,
        s1,
        selectedSeats,
        "stripe");

    return 0;
}