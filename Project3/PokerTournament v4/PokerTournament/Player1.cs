using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

// Decision Tree - OODA Loop - Observe, Orient, Decide, Act
//
// Bet - desired vs limit - based on starting funds and opponent aggression - read opponent to see which works better
//     Bait - lower bet to get opponent to go in
//     Bluff - higher bet to scare opponent out

namespace PokerTournament
{
    class Player1 : Player
    {
        private Random rand;
        private int initialMoney;
        private int[] scores_r1;
        private int[] scores_r2;
        private float[] bets_r1;
        private float[] bets_r2;

        public Player1(int idNum, string name, int money) : base(idNum, name, money)
        {
            rand = new Random();
            initialMoney = money;
            scores_r1 = new int[] { 1, 2, 3, 4, 4, 4, 5, 5, 5, 5 };
            scores_r2 = new int[] { 0, 1, 2, 3, 4, 4, 4, 5, 5, 5 };
            bets_r1 = new float[] { 0.00f, 0.00f,   0.00f, 0.01f,   0.01f, 0.05f,   0.02f, 0.10f,   0.05f, 0.25f,   0.05f, 0.50f };
            bets_r2 = new float[] { 0.00f, 0.00f,   0.01f, 0.05f,   0.03f, 0.10f,   0.10f, 0.25f,   0.25f, 0.75f,   0.50f, 5.00f };
        }
        public override PlayerAction BettingRound1(List<PlayerAction> actions, Card[] hand)
        {
            float aggression = ((float)Money / (float)initialMoney) * 0.5f + 0.5f;

            Card highCard;
            int handEval = Evaluate.RateAHand(this.Hand, out highCard);

            int currentScore = scores_r1[handEval - 1];
            int newBet = (int)(bets_r1[currentScore * 2] * aggression * (float)initialMoney);
            int maxBet = (int)(bets_r1[currentScore * 2 + 1] * (float)initialMoney);

            ListTheHand(hand);

            return MakeBet(actions, "Bet1", newBet, maxBet);
        }

        public override PlayerAction BettingRound2(List<PlayerAction> actions, Card[] hand)
        {
            float aggression = ((float)Money / (float)initialMoney) * 0.5f + 0.5f;

            Card highCard;
            int handEval = Evaluate.RateAHand(this.Hand, out highCard);

            int currentScore = scores_r2[handEval - 1];
            int newBet = (int)(bets_r2[currentScore * 2] * aggression * (float)initialMoney);
            int maxBet = (int)(bets_r2[currentScore * 2 + 1] * (float)initialMoney);

            ListTheHand(hand);

            return MakeBet(actions, "Bet2", newBet, maxBet);
        }

        //Handles discarding and drawing new cards
        public override PlayerAction Draw(Card[] hand)
        {
            Card highCard;
            int handEval = Evaluate.RateAHand(hand, out highCard);
            int discardCount = 0;

            // Don't mess with good non-pair-based hands
            if (handEval == 5 || handEval == 6 || handEval == 9 || handEval == 10)
            {
                return new PlayerAction(Name, "Draw", "stand pat", 0);
            }

            for (int i = 0; i < 5; ++i)
            {
                int cardValue = hand[i].Value;
                bool cardMatched = false;
                for (int j = 0; j < 5; ++j)
                {
                    if (i != j && hand[j] != null && cardValue == hand[j].Value)
                    {
                        cardMatched = true;
                        break;
                    }
                }

                if (!cardMatched)
                {
                    hand[i] = null;
                    discardCount++;
                }
            }

            return new PlayerAction(Name, "Draw", "draw", discardCount);
        }

        // helper method - list the hand
        private void ListTheHand(Card[] hand)
        {
            // evaluate the hand
            Card highCard = null;
            int rank = Evaluate.RateAHand(hand, out highCard);

            // list your hand
            Console.WriteLine("\nName: " + Name + " Your hand:   Rank: " + rank);
            for (int i = 0; i < hand.Length; i++)
            {
                Console.Write(hand[i].ToString() + " ");
            }
            Console.WriteLine();
        }

        // Bet and Raise are just the same thing - fuse them here with call and check to make the system happy without convoluting our code
        private PlayerAction MakeBet(List<PlayerAction> playerActions, string currentBet, int betValue, int maxValue)
        {
            int bet = 0;
            bool shouldRaise = false;

            // Figure out the current bet (why doesn't the game have this built in?)
            for (int i = 0; i < playerActions.Count; i++)
            {
                if (playerActions[i].ActionName.Equals("bet") || playerActions[i].ActionName.Equals("raise"))
                {
                    bet += playerActions[i].Amount;
                    shouldRaise = true;
                }
                else if (playerActions[i].ActionName.Equals("draw"))
                {
                    shouldRaise = false;
                }
            }

            // Not worth trying to play it
            if (bet > maxValue)
            {
                Console.WriteLine("Folding - {0}/{1}/{2}", bet, betValue, maxValue);
                return new PlayerAction(Name, currentBet, "fold", 0);
            }

            if (bet > Money)
            {
                bet = Money;
            }

            // We want to (and can) up it
            if (betValue > bet)
            {
                if (shouldRaise)
                {
                    Console.WriteLine("Raising - {0}/{1}/{2}", bet, betValue, maxValue);
                    return new PlayerAction(Name, currentBet, "raise", betValue - bet);
                }
                else
                {
                    Console.WriteLine("Betting - {0}/{1}/{2}", bet, betValue, maxValue);
                    return new PlayerAction(Name, currentBet, "bet", betValue - bet);
                }
            }

            // Higher than we want but not unreasonable - match it
            if (bet != 0)
            {
                Console.WriteLine("Calling - {0}/{1}/{2}", bet, betValue, maxValue);
                return new PlayerAction(Name, currentBet, "call", 0);
            }
            else
            {
                Console.WriteLine("Checking - {0}/{1}/{2}", bet, betValue, maxValue);
                return new PlayerAction(Name, currentBet, "check", 0);
            }
        }
    }
}
